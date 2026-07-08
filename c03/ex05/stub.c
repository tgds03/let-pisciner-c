#include <string.h>
#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main() {
	char b1[10], b2[10];
	char *str1 = "1234";
	char *str2 = "";
	char line[11] = {0, };
	int temp;

	for (int i = 0; i < 10; ++i) {
		b1[i] = (i % 2) ? 0 : '.';
		b2[i] = '.';
	}

	for (int i = 0; i < 10; ++i) {
		printf("%d %s\n", ft_strlcat(b1, str1, i), b1);
		printf("%d %s\n", ft_strlcat(b1, str2, i), b1);
	}

	for (int i = 0; i < 10; ++i) {
		temp = ft_strlcat(b2, str1, 10);
		memcpy(line, b2, 10);
		printf("%d %s\n", temp, line);

		temp = ft_strlcat(b2, str2, 10);
		memcpy(line, b2, 10);
		printf("%d %s\n", temp, line);
	}
	return 0;
}
