#include <stdio.h>

char *ft_strcapitalize(char *str);

int main() {
	char a[100] = "hi, hOw ArE yOu? 42words forty-two;fifty_and+one\0siX-SeVen";
	printf("%s", ft_strcapitalize(a));
	return 0;
}
