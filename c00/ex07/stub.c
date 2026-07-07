#include "common.h"

unsigned int write(int fildes, const void *buf, unsigned int nbyte);
void ft_putnbr(int nb);

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
