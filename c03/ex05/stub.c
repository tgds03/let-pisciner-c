#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main() {
	char buffer[21] = "....................";
	char *str1 = "123";
	char *str2 = "";
	char *offset = buffer + 5;
	for (int i = 0; i < 5; ++i) {
		printf("%d %s\n", ft_strlcat(offset, str1, 11), buffer);
		printf("%d %s\n", ft_strlcat(offset, str2, 11), buffer);
	}
	printf("%d %s\n", ft_strlcat(offset, str1, 0), buffer);
	printf("%d %s\n", ft_strlcat(offset, str2, 0), buffer);
	return 0;
}
