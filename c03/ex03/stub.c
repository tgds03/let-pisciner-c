#include <stdio.h>
#include <string.h>

int main()
{
	char d[100] = "";
	char *s1 = "0123456789";
	char *s2 = "";
	printf("%s\n", d);
	printf("%s\n", strncat(d, s1, 0));
	printf("%s\n", strncat(d, s2, 1));
	printf("%s\n", strncat(d, s1, 2));
	printf("%s\n", strncat(d, s2, 3));
	printf("%s\n", strncat(d, s1, 5));
	printf("%s\n", strncat(d, s1, 10));
	printf("%s\n", strncat(d, s1, 20));
	return 0;
}
