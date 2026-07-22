#include <stdio.h>
#include "common.h"
#include "ft.h"

void ft_putchar(char c) {
	UNUSED(c);
	printf("ft_putchar()\n");
}

void ft_swap(int *a, int *b) {
	UNUSED(a);
	UNUSED(b);
	printf("ft_swap()\n");
}

void ft_putstr(char *str) {
	UNUSED(str);
	printf("ft_putstr()\n");
}

int ft_strlen(char *str) {
	UNUSED(str);
	printf("ft_strlen()\n");
	return 0;
}

int ft_strcmp(char *s1, char *s2) {
	UNUSED(s1);
	UNUSED(s2);
	printf("ft_strcmp()\n");
	return 0;
}
