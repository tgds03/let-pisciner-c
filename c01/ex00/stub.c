// genparam>> SET_INPUT 0
// genparam>> REPEAT 10 RANDOMIZE_INPUT int
#include "common.h"
#include <stdio.h>
#include <stdlib.h>

FUNCTION(void, ft_ft, int *nbr);

void test(int argc, char* argv[]) {
	UNUSED(argc);
	int n = atoi(argv[1]);
	ft_ft(&n);
	printf("%d", n);
}
