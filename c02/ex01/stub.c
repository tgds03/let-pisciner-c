#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n);

int main() {
	char *str1 = "1234567890";
	char *str2 = "";
	char *str3 = "abcd\0abcd";
	char buffer[20];
	ft_strncpy(buffer, str1, 10);
	printf("%s\n", buffer);
	ft_strncpy(buffer, str2, 10);
	printf("%s\n", buffer);
	ft_strncpy(buffer, str3, 10);
	printf("%s\n", buffer);
	return 0;
}
