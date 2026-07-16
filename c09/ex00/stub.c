// genparam>> SET_INPUT 0 0
// genparam>> SET_INPUT 1 2
// genparam>> SET_INPUT abcde 58291
// genparam>> SET_INPUT younamsayng? younamsayng?
#include <stdlib.h>
#include <stdio.h>
#include "ft.h"
#include "common.h"

void test(int argc, char *argv[]) {
	UNUSED(argc);
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c;

	printf("ft_putchar(%s):\t", argv[1]); fflush(stdout);
	ft_putchar(*argv[1]);
	printf("\n");

	printf("ft_swap(%d, %d):\t", a, b);
	ft_swap(&a, &b);
	printf("%d, %d\n", a, b);

	printf("ft_putstr(%s):\t", argv[1]); fflush(stdout);
	ft_putstr(argv[1]);
	printf("\n");

	printf("ft_strlen(%s):\t%d\n", argv[1], ft_strlen(argv[1]));

	printf("ft_strcmp(%s, %s):\t", argv[1], argv[2]);
	
	c = ft_strcmp(argv[1], argv[2]);
	if (c > 0) {
		printf("%s > %s\n", argv[1], argv[2]);
	} else if (c < 0) {
		printf("%s < %s\n", argv[1], argv[2]);
	} else {
		printf("%s == %s\n", argv[1], argv[2]);
	}
}
