#include <stdio.h>

int ft_str_is_alpha(char *str);

int main() {
	char c[2] = "\0\0";
	printf("%d", ft_str_is_alpha(""));
	for (char i = 32; i < 127; ++i) {
		c[0] = i;
		printf("%d", ft_str_is_alpha(c));
	}
	return 0;
}
