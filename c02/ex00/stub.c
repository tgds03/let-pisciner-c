#include <stdio.h>

char *ft_strcpy(char *dest, char *src);

int main() {
	char *str1 = "1234567890";
	char *str2 = "";
	char *str3 = "abcd\0abcd";
	char buffer[20];
	ft_strcpy(buffer, str1);
	printf("%s\n", buffer);
	ft_strcpy(buffer, str2);
	printf("%s\n", buffer);
	ft_strcpy(buffer, str3);
	printf("%s\n", buffer);
	return 0;
}
