#include "common.h"
#include <stdio.h>

FUNCTION(void, ft_putchar, char c);

void test(int argc __attribute__((unused)), char *argv[]) {
	printf("%p %s\n", target_info.name);
	ft_putchar(*argv[1]);
}

int main() {
	init_test(__FILE__);
	loop_test(test);
	return 0;
}
