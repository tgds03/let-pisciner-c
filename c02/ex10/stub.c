// #include "bsd/string.h"
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
	char buffer[80], *offset;
	offset = buffer + 20;

	fill(buffer, 80);
	printf("%d %s\n", (int)ft_strlcpy(offset, str1, 20), buffer);
	fill(buffer, 80);
	printf("%d %s\n", (int)ft_strlcpy(offset, str2, 20), buffer);
	fill(buffer, 80);
	printf("%d %s\n", (int)ft_strlcpy(offset, str3, 20), buffer);
	fill(buffer, 80);
	printf("%d %s\n", (int)ft_strlcpy(offset, str4, 20), buffer);
	fill(buffer, 80);
	printf("%d %s\n", (int)ft_strlcpy(offset, str5, 20), buffer);
	fill(buffer, 80);
	printf("%d %s\n", (int)ft_strlcpy(offset, str5, 0), buffer);
	return 0;
}
