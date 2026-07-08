#include <stdio.h>
#include "common.h"

unsigned int write(int fildes, const void *buf, unsigned int nbyte);
void ft_putnbr(int nb);

int main() {
	int test_values[8] = { ~(1<<31), 100, 10, 1, 0, -1, -10, 1<<31 };
	for (int i = 0; i < 8; ++i) {
		ft_putnbr(test_values[i]);
		write(1, "\n", 1);
		// printf("%d\n", test_values[i]);
	}

	init_rand(__FILE__);
	for (int i = 0; i < 10; ++i) {
		ft_putnbr(rand());
		write(1, "\n", 1);
		// printf("%d\n", rand());
	}
	return 0;
}
