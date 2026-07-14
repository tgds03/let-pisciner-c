// genparam>> SET_INPUT -1
// genparam>> SET_INPUT 0
// genparam>> SET_INPUT 1
// genparam>> REPEAT 10 RANDOMIZE_INPUT int
#include "common.h"
#include <stdlib.h>

FUNCTION(void, ft_putnbr, int nb);
void test(int argc, char *argv[]) {
	ft_putnbr(atoi(argv[1]));
}