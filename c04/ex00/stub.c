#include <stdio.h>

int ft_strlen(char *str);

int main() {
	char *str0 = "";
	char *str1 = "0123456789";
	char *str2 = "abcdefghij\0" "klmnopqrst";
	
	printf("%d ", ft_strlen(str0));
	printf("%d ", ft_strlen(str1));
	printf("%d ", ft_strlen(str2));
	return 0;
}
