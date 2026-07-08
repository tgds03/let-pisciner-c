# Let pisciner C

에꼴42 C Piscine 과정의 과제들을 동료평가하기 위한 도구입니다. 포맷팅 검사 (norminette), 컴파일, 간이 테스트를 자동으로 진행해 줍니다.

## 사용법 및 예시

```bash
piscinerc [repo_path] [project_name]
```

아래와 같은 레포지토리를 예시로

```
my_exam_c00
├── ex00
│   └── ft_putchar.c
├── ex01
│   └── ft_print_alphabet.c
├── ex02
│   └── ft_print_reverse_alphabet.c
├── ex03
│   └── ft_print_numbers.c
├── ex04
│   └── ft_is_negative.c
├── ex05
│   └── ft_print_comb.c
├── ex06
│   └── ft_print_comb2.c
├── ex07
│   └── ft_putnbr.c
└── ex08
    └── ft_print_combn.c
```

아래처럼 실행하면 됩니다.

```bash
piscinerc my_exam_c00 c00
```

실행을 성공적으로 마치면 아래 과정이 차례대로 실행됩니다.

1. 레포지토리에서 norminette 검사
2. 준비된 stub.c 파일을  ex00, ex01, ... 디렉토리로 이동
3. 컴파일 및 실행
4. expected\_output과 결과 비교
5. 현재 위치에 [repo\_name]\_outputs 디렉토리를 생성하고 실행 결과를 이곳에 저장

## 설치

shell에서 아래 스크립트를 실행해 주세요.

```bash
git clone git@github.com:tgds03/let-pisciner-c.git let-pisciner-c
cd let-pisciner-c
mkdir ~/bin
ln -s piscinerc ~/bin/piscinerc
```
