#include "common.h"
#include <stdlib.h>

FUNCTION(void, ft_putnbr, int nb);
void test(int argc, char *argv[]) {
	if (argc != 2) {
		printf("you must to give 1 argument");
		return;
	}
	ft_putnbr(atoi(argv[1]));
}
/*
int main() {
	ft_putnbr(~(1<<31));
	write(1, "\n", 1);
	ft_putnbr(100);
	write(1, "\n", 1);
	ft_putnbr(10);
	write(1, "\n", 1);
	ft_putnbr(1);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(-1);
	write(1, "\n", 1);
	ft_putnbr(-10);
	write(1, "\n", 1);
	ft_putnbr(1<<31);
	write(1, "\n", 1);

	init_rand(__FILE__);
	for (int i = 0; i < 10; ++i) {
		ft_putnbr(rand());
		write(1, "\n", 1);
	}
	return 0;
}
*/
