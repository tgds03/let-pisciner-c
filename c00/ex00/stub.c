// genparam>> REPEAT 10 RANDOMIZE_INPUT pchar
#include "common.h"
#include <stdio.h>

FUNCTION(void, ft_putchar, char c);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	ft_putchar(*argv[1]);
}
