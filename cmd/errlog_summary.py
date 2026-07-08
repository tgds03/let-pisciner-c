#!/usr/bin/env python3
"""
asan_summary.py

실행 결과를 3가지로 구분해서 한 줄 요약한다:
  [PASS]       - 정상 종료 (메모리 에러 없음)
  [ASAN FAIL]  - ASan이 감지한 메모리 에러로 종료
  [OTHER FAIL] - ASan과 무관한 다른 이유로 비정상 종료 (segfault, assert 등)

사용법 1 (바이너리 경로를 직접 인자로 넘기기 - 종료 코드까지 정확히 판단 가능):
    python3 asan_summary.py ./내_ASan_바이너리 [실행 인자들...]
    python3 asan_summary.py ./test1 ./test2 ./test3   # 여러 개 한 번에

사용법 2 (파이프로 로그 넘기기 - stdin):
    ./내_ASan_바이너리 2>&1 | python3 asan_summary.py
    cat asan_log.txt | python3 asan_summary.py

    주의: 파이프(|)로 그냥 넘기면 파이썬 스크립트가 원래 프로그램의 종료 코드를
    알 수 없다 (파이프 중간 명령의 종료 코드는 그 자리에서 즉시 사라짐).
    ASan 로그 자체는 stdin 텍스트만으로도 잡아내지만, "OTHER FAIL"(ASan과
    무관한 crash)까지 정확히 구분하려면 종료 코드를 먼저 변수로 캡처한 뒤
    --exit-code 로 넘겨준다:

    output=$(./내_ASan_바이너리 2>&1)
    code=$?
    echo "$output" | python3 asan_summary.py --exit-code=$code

사용법 3 (종료 코드는 변수로, stderr 로그는 파일로 각각 저장한 뒤 넘기기 - 가장 안전):
    ./내_ASan_바이너리 > out.log 2> err.log
    code=$?
    python3 asan_summary.py --log-file=err.log --exit-code=$code

    (run_tests.sh 를 쓰면 여러 바이너리에 대해 이 과정을 자동으로 해준다)
"""

import re
import signal
import subprocess
import sys


def parse_asan_output(stderr: str):
    """ASan stderr 텍스트에서 핵심 정보를 뽑아 dict로 반환. 에러 없으면 None."""
    m_type = re.search(r"ERROR: AddressSanitizer: (\S+)", stderr)
    if not m_type:
        return None

    result = {
        "bug_type": m_type.group(1),
        "access": None,
        "size": None,
        "file": None,
        "line": None,
        "func": None,
        "var": None,
    }

    m_access = re.search(r"(READ|WRITE) of size (\d+)", stderr)
    if m_access:
        result["access"] = m_access.group(1)
        result["size"] = m_access.group(2)

    m_frame = re.search(r"#0\s+0x\S+\s+in\s+(\S+)\s+(\S+\.c):(\d+)", stderr)
    if m_frame:
        result["func"] = m_frame.group(1)
        result["file"] = m_frame.group(2).split("/")[-1]
        result["line"] = m_frame.group(3)

    m_var = re.search(r"'(\w+)'\s*\(line \d+\)[^\n]*\n[^\n]*overflows this variable", stderr)
    if not m_var:
        m_var = re.search(r"allocated by thread T0 here[^\n]*\n[^\n]*in (\w+)", stderr)
    if m_var:
        result["var"] = m_var.group(1)

    return result


def signal_name(sig_num: int) -> str:
    try:
        return signal.Signals(sig_num).name
    except ValueError:
        return f"signal {sig_num}"


def classify(label: str, text: str, returncode) -> str:
    """
    returncode 의미:
      None  -> 알 수 없음 (stdin 파이프 모드에서 --exit-code 안 준 경우)
      0     -> 정상 종료
      >0    -> 그 코드로 종료 (일반적으로 ASan 기본은 1)
      <0    -> 파이썬 subprocess 관례상 -N이면 시그널 N으로 죽음 (직접 실행 모드에서만 발생)
    """
    parsed = parse_asan_output(text)

    if parsed is not None:
        loc = f"{parsed['file']}:{parsed['line']}" if parsed["file"] else "위치 불명"
        func = parsed["func"] or "?"
        access = parsed["access"] or "?"
        size = parsed["size"] or "?"
        var = f", 대상 변수 '{parsed['var']}'" if parsed["var"] else ""
        return (
            f"[FAIL] [ASan] {parsed['bug_type']} "
            f"({access} size={size}) at {loc} in {func}(){var}"
        )

    if returncode is None:
        return f"[UNKNOWN] ASan 로그 없음, 종료 코드 정보 없음 (--exit-code=${{PIPESTATUS[0]}} 사용 권장)"

    if returncode == 0:
        return f"[PASS]"

    if returncode < 0:
        sig = signal_name(-returncode)
        return f"[FAIL] {sig}"

    return f"[FAIL] exit code={returncode}"


def run_and_summarize(binary_path: str, args=None) -> str:
    cmd = [binary_path] + (args or [])
    proc = subprocess.run(cmd, capture_output=True, text=True)
    return classify(binary_path, proc.stderr, proc.returncode)


def summarize_stdin(exit_code) -> str:
    text = sys.stdin.read()
    return classify("stdin", text, exit_code)


def main():
    args = sys.argv[1:]

    exit_code_override = None
    log_file = None
    remaining = []
    for a in args:
        if a.startswith("--exit-code="):
            try:
                exit_code_override = int(a.split("=", 1)[1])
            except ValueError:
                pass
        elif a.startswith("--log-file="):
            log_file = a.split("=", 1)[1]
        else:
            remaining.append(a)

    # --log-file 이 주어진 경우: 파일에서 로그를 읽어 종료 코드와 함께 요약
    if log_file:
        try:
            with open(log_file, "r", errors="replace") as f:
                text = f.read()
        except OSError as e:
            print(f"[ERROR] 로그 파일을 읽을 수 없음: {log_file} ({e})")
            sys.exit(2)
        summary = classify(log_file, text, exit_code_override)
        print(summary)
        sys.exit(0 if summary.startswith("[PASS]") else 1)

    # 바이너리 경로가 주어진 경우: 직접 실행해서 정확한 종료 코드까지 판단
    if remaining:
        exit_code = 0
        for b in remaining:
            summary = run_and_summarize(b)
            print(summary)
            if not summary.startswith("[PASS]"):
                exit_code = 1
        sys.exit(exit_code)

    # 인자 없이 stdin으로만 들어온 경우
    if not sys.stdin.isatty():
        summary = summarize_stdin(exit_code_override)
        print(summary)
        sys.exit(0 if summary.startswith("[PASS]") else 1)

    print(__doc__)
    sys.exit(1)


if __name__ == "__main__":
    main()
