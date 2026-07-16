// genparam>> SET_INPUT -1
// genparam>> SET_INPUT 0
// genparam>> SET_INPUT 1
// genparam>> SET_INPUT 10
// genparam>> SET_INPUT -10
// genparam>> SET_INPUT 42
// genparam>> SET_INPUT -42
// genparam>> REPEAT 4 RANDOMIZE_INPUT int
#include <stdlib.h>
#include <stdio.h>
#include "ft_abs.h"
#include "common.h"

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d", ABS(atoi(argv[1])));
}
