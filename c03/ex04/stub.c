#include <stdio.h>

char *ft_strstr(char *str, char *to_find);

int main()
{
	char *s1 = "0123456789";
	char *s2 = "0123";
	char *s3 = "789";
	char *s4 = "3456";
	char *s5 = "";
	printf("%s\n", ft_strstr(s1, s2));
	printf("%s\n", ft_strstr(s1, s3));
	printf("%s\n", ft_strstr(s1, s4));
	printf("%s\n", ft_strstr(s1, s5));
	printf("%s\n", ft_strstr(s5, s5));
	printf("%p\n", ft_strstr(s2, s4));
	printf("%p\n", ft_strstr(s5, s1));
	return 0;
}
