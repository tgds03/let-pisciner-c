#include "common.h"

unsigned int write(int fildes, const void *buf, unsigned int nbyte);
void ft_putnbr_base(int nbr, char *base);

void fill_random_str(char *dest, int size) {
	int i;
	for (i = 0; i < size - 1; ++i) {
		dest[i] = 32 + rand() % 95;
	}
	dest[i] = 0;
}

int main() {
	char *base0 = "";
	char *base1 = "0";
	char *base2 = "01";
	char *base7 = "0123456";
	char *base10 = "0123456789";
	char *base13 = "0123456789abc";
	char *base16 = "0123456789abcdef";
	char basebuffer[32];
	int test_values[8] = { ~(1<<31), 100, 10, 1, 0, -1, -10, 1<<31 };

	ft_putnbr_base(1234, base0);
	ft_putnbr_base(1234, base1);

	for (int i = 0; i < 8; ++i) {
		ft_putnbr_base(test_values[i], base2);
		write(1, "\n", 1);
		ft_putnbr_base(test_values[i], base7);
		write(1, "\n", 1);
		ft_putnbr_base(test_values[i], base10);
		write(1, "\n", 1);
		ft_putnbr_base(test_values[i], base13);
		write(1, "\n", 1);
		ft_putnbr_base(test_values[i], base16);
		write(1, "\n\n", 2);
	}

	init_rand(__FILE__);
	for (int i = 0; i < 10; ++i) {
		fill_random_str(basebuffer, rand() % 32);
		ft_putnbr_base(rand(), basebuffer);
		write(1, "\n", 1);
	}
	return 0;
}
