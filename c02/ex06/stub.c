#include <stdio.h>

int ft_str_is_printable(char *str);

int main() {
	char c[2] = "\0";
	printf("%d", ft_str_is_printable(""));
	for (int i = 0; i < 128; ++i) {
		c[0] = (char)i;
		printf("%d", ft_str_is_printable(c));
	}
	return 0;
}
