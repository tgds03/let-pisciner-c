// genparam>> REPEAT 10 $(32 + \i)
#include "common.h"

FUNCTION(void, ft_putstr, char *str);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	ft_putstr(argv[1]);
}
