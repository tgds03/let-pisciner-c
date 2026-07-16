# Let pisciner C

에꼴42 C Piscine 과정의 과제들을 동료평가하기 위한 도구입니다. 포맷팅 검사 (norminette), 컴파일, 간이 테스트를 자동으로 진행해 줍니다.

## 주의사항

- 진행 과정에서 레포지토리에 git clean이 실행됩니다. 이는 커밋되지 않은 파일을 모두 지우는 명령어이므로 **반드시 필요한 모든 파일이 커밋되었음을 확인한 후 실행하시길 바랍니다.**
- **간이 테스트는 Pass를 보장해주지 않습니다.** 이 프로그램이 수행하는 테스트에 의존하시지 않기를 바랍니다.
- 평가자 역시 간이 테스트 결과만으로 평가하시지 말고 피평가자가 작성하신 코드를 직접 읽으며 평가하시길 바랍니다.
- 기여자가 pisciner인 관계로 stub 및 간이 테스트 구현은 진행 중에 있습니다.

## 사용법 및 예시

```bash
piscinerc [repo_path] [project_name]
```

아래와 같은 레포지토리를 예시로

```
my_exam_c00
├── ex00
│   └── ….c
├── ex01
│   └── ….c
├── ex02
│   ︙
└── ex08
    └── ….c
```

아래처럼 실행하면 됩니다.

```bash
piscinerc my_exam_c00 c00
```

`piscinerc`를 실행하면 아래 과정이 차례대로 수행됩니다.

1. 레포지토리에서 norminette 검사
2. 준비된 stub.c 파일을  ex00, ex01, ... 디렉토리로 이동
3. 컴파일 및 실행
4. expected\_output과 결과 비교
5. 현재 위치에 [repo\_name]\_outputs 디렉토리를 생성하고 실행 결과를 이곳에 저장
6. [repo\_name]에서 `git clean`으로 파일 정리

## 설치

shell에서 아래 스크립트를 실행해 주세요.

```bash
git clone https://github.com/tgds03/let-pisciner-c.git let-pisciner-c
cd let-pisciner-c
pip install -r requirements.txt
mkdir ~/bin
ln -s "$(pwd)/piscinerc" ~/bin/piscinerc
```

# Description

`c00`, `c01`, ... 등의 레포지토리에는 각각 다음 파일이 있습니다.

- `stub.c`: 제출 코드가 컴파일이 가능하도록 `main()` 등의 함수가 작성된 stub 코드입니다.
- `expected_output`: 간이 테스트에 활용되는 기준 출력값입니다. 간이 테스트는 Pass를 보장하지 않습니다.
- `env`: 코드가 추가 라이브러리나 컴파일 옵션을 요구하는 경우 사용됩니다. 필요한 exam에만 있습니다.

`include` 에는 stub에 필요한 공통 라이브러리 헤더 (`common.h`)와 일부 코드에 필요한 추가 라이브러리 헤더가 위치해 있습니다. 이에 대응되는 라이브러리는 `lib`에 위치하며, 외부 라이브러리가 아닌 경우 `src`에 해당 소스코드도 포함되어 있습니다.

`cmd`에는 실행에 필요한 부가적인 shell 파일들이 있습니다.

`piscinerc`는 실행되는 메인 shell 파일이며, 다음을 수행합니다. 각 과정은 콘솔에 출력됩니다.

1. 레포지토리에서 norminette 검사
2. 준비된 stub.c 파일을  ex00, ex01, ... 디렉토리로 이동
3. 컴파일 및 실행
4. expected\_output과 결과 비교
5. 현재 위치에 [repo\_name]\_outputs 디렉토리를 생성하고 실행 결과를 이곳에 저장
6. [repo\_name]에서 `git clean`으로 파일 정리

# Dependency

이 프로젝트는 아래와 같은 환경에서 개발되었습니다.

- Ubuntu 22.04.1 
- cc 11.4.0
- python 3.13.1
- pycparser 3.0

# Structure

```
let-pisciner-c
├── c00
│   ├── ex00
│   │   ├── expected_output
│   │   └── stub.c
│   ├── ex01
│   │   ├── expected_output
│   │   └── stub.c
│   ├── ex02
│   ︙
├── c01
│   ├── ex00
│   │   ├── expected_output
│   │   └── stub.c
│   ├── ex01
│   │   ├── expected_output
│   │   └── stub.c
│   ├── ex02
│   ︙
├── c02
├── c03
︙
├── cmd
│   ├── compile_exam.sh
│   ├── gen-expected.sh
│   └── test_exam.sh
├── include
│   ├── common.h
│   ︙
├── lib
├── piscinerc
├── README.md
└── src
```
