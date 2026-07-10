#include "common.h"
#include <stdio.h>

FUNCTION(void, ft_putchar, char c)

void test(int argc __attribute__((unused)), char *argv[]) {
	char *cur = argv[1];
	while (*cur) {
		ft_putchar(*cur++);
	}
}

int main() {
	init_test(__FILE__);
	loop_test(test);
	return 0;
}
