#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);

int main()
{
	char d[100] = "";
	char *s1 = "0123456789";
	char *s2 = "01234\06789";
	char *s3 = "";
	printf("%s\n", d);
	printf("%s\n", ft_strncat(d, s1, 0));
	printf("%s\n", ft_strncat(d, s3, 1));
	printf("%s\n", ft_strncat(d, s1, 2));
	printf("%s\n", ft_strncat(d, s3, 3));
	printf("%s\n", ft_strncat(d, s1, 5));
	printf("%s\n", ft_strncat(d, s1, 10));
	printf("%s\n", ft_strncat(d, s1, 20));
	printf("%s\n", ft_strncat(d, s2, 20));
	printf("%s\n", ft_strncat(d, s2, 20));
	return 0;
}
