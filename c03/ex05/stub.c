#include <stdio.h>
#include <string.h>

int main() {
	char buffer[10] = "12345";
	char *str1 = "12";
	char *str2 = "";
	printf("%d %s\n", strlcat(buffer, str1, 10), buffer);
	printf("%d %s\n", strlcat(buffer, str2, 10), buffer);
	printf("%d %s\n", strlcat(buffer, str1, 10), buffer);
	printf("%d %s\n", strlcat(buffer, str2, 10), buffer);
	printf("%d %s\n", strlcat(buffer, str1, 10), buffer);
	printf("%d %s\n", strlcat(buffer, str2, 10), buffer);
	printf("%d %s\n", strlcat(buffer, str1, 10), buffer);
	printf("%d %s\n", strlcat(buffer, str2, 10), buffer);
	return 0;
}
