#include <stdio.h>

int ft_str_is_lowercase(char *str);

int main() {
	char c[2] = "\0\0";
	printf("%d", ft_str_is_lowercase(""));
	for (char i = 32; i < 127; ++i) {
		c[0] = i;
		printf("%d", ft_str_is_lowercase(c));
	}
	return 0;
}
