#include "common.h"
#include <stdio.h>

FUNCTION(void, ft_putchar, char c);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	ft_putchar(*argv[1]);
}
