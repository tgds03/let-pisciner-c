#include <stdio.h>
#include "common.h"

int ft_atoi_base(char *str, char *base);

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
	char *base10 = "0123456789";
	// char *base16 = "0123456789abcdef";
	char basebuffer[16];
	char numberbuffer[32];

	char *str[12] = {
		"", "1", "0", "-1", 
		"2147483648", "2147483647", "-2147483648", "-2147483649", 
		" \f\n\r\t\v3 1", "\t\v +---+--23", "\r +- -+32", "    +-++\t352"
	};

	ft_atoi_base("1234", base0);
	ft_atoi_base("1234", base1);

	for (int i = 0; i < 12; ++i) {
		printf("%d\n", ft_atoi_base(str[i], base10));
	}

	init_rand(__FILE__);
	for (int i = 0; i < 10; ++i) {
		fill_random_str(basebuffer, rand() % 16);
		fill_random_str(numberbuffer, 32);
		printf("%d\n", ft_atoi_base(numberbuffer, basebuffer));
	}
	return 0;
}
