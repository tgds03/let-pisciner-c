#include <stdio.h>

char *ft_strcat(char *dest, char *src);

int main()
{
	char d[100] = "";
	char *s1 = "0123456789";
	char *s2 = "";
	printf("%s\n", d);
	printf("%s\n", ft_strcat(d, s1));
	printf("%s\n", ft_strcat(d, s2));
	printf("%s\n", ft_strcat(d, s1));
	printf("%s\n", ft_strcat(d, s2));
	return 0;
}
