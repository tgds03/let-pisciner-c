#include "common.h"
#include <stdio.h>

FUNCTION(void, ft_putchar, char c);

void test(int argc __attribute__((unused)), char *argv[]) {
	ft_putchar(*argv[1]);
}

int main() {
	init_test();
	loop_test(test);
	return 0;
}
