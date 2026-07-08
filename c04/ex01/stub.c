#include <stdio.h>

void ft_putstr(char *str);

char *str = "abcdefg\nhijklmn";
char c[2] = {0, };

void test_expected() {
	printf("%s\n", str);
	for (char i = 32; i < 127; ++i) {
		c[0] = i;
		printf("%s", c);
	}
	printf("%s\n", str);
}

void test() {
	ft_putstr(str);
	ft_putstr("\n");
	for (char i = 32; i < 127; ++i) {
		c[0] = i;
		ft_putstr(c);
	}
	ft_putstr(str);
	ft_putstr("\n");
}

int main() {
	test();
}
