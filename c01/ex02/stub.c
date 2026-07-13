// )#> RANDOMIZE_INPUT int int
#include "common.h"
#include <stdio.h>
#include <stdlib.h>

FUNCTION(void, ft_swap, int *a, int *b);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	int a, b;
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	ft_swap(&a, &b);
	printf("%d, %d", a, b);
}
