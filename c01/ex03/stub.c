// genparam>> REPEAT 10 RANDOMIZE_INPUT int int
#include "common.h"
#include <stdio.h>

FUNCTION(void, ft_div_mod, int a, int b, int *div, int *mod);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	int a, b, div, mod;
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	ft_div_mod(a, b, &div, &mod);
	printf("%d %d", div, mod);
}
