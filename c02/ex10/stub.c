#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

void fill(char *arr, int size) {
	for (int i = 0; i < size - 1; ++i) {
		arr[i] = '.';
	}
	arr[size - 1] = 0;
}

int main() {
	char *str1 = "";
	char *str2 = "abcde";
	char *str3 = "abcdefghijklmnopqrst";
	char *str4 = "abcdefghijklmnopqrstu";
	char *str5 = "abcdefghijklmnopqrstuvwxyz";
	char buffer[21];

	fill(buffer, 21);
	printf("%d %s\n", ft_strlcpy(buffer, str1, 21), buffer);
	fill(buffer, 21);
	printf("%d %s\n", ft_strlcpy(buffer, str2, 21), buffer);
	fill(buffer, 21);
	printf("%d %s\n", ft_strlcpy(buffer, str3, 21), buffer);
	fill(buffer, 21);
	printf("%d %s\n", ft_strlcpy(buffer, str4, 21), buffer);
	fill(buffer, 21);
	printf("%d %s\n", ft_strlcpy(buffer, str5, 21), buffer);
	return 0;
}
