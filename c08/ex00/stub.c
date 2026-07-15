#include <stdio.h>
#include "ft.h"
#include "common.h"

void ft_putchar(char c) {
	printf("ft_putchar()\n");
}

void ft_swap(int *a, int *b) {
	printf("ft_swap()\n");
}

void ft_putstr(char *str) {
	printf("ft_putstr()\n");
}

int ft_strlen(char *str) {
	printf("ft_strlen()\n");
	return 0;
}

int ft_strcmp(char *s1, char *s2) {
	printf("ft_strcmp()\n");
	return 0;
}

void test(int argc, char *argv[]) {
	UNUSED(argc);
	UNUSED(argv);
	ft_putchar('a');
	ft_swap(0, 0);
	ft_putstr(0);
	ft_strlen(0);
	ft_strcmp(0, 0);
	return 0;
}
