#include <stdio.h>
#include <string.h>

int main()
{
	char d[100] = "";
	char *s1 = "0123456789";
	char *s2 = "";
	printf("%s\n", d);
	printf("%s\n", strcat(d, s1));
	printf("%s\n", strcat(d, s2));
	printf("%s\n", strcat(d, s1));
	printf("%s\n", strcat(d, s2));
	return 0;
}
