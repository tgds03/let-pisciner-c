#include <stdio.h>
#include <string.h>

int main() {
	char buffer[11] = "12345";
	char *str1 = "12";
	char *str2 = "";
	printf("%d %s\n", strlcat(buffer, str1, 11), buffer);
	printf("%d %s\n", strlcat(buffer, str2, 11), buffer);
	printf("%d %s\n", strlcat(buffer, str1, 11), buffer);
	printf("%d %s\n", strlcat(buffer, str2, 11), buffer);
	printf("%d %s\n", strlcat(buffer, str1, 11), buffer);
	printf("%d %s\n", strlcat(buffer, str2, 11), buffer);
	printf("%d %s\n", strlcat(buffer, str1, 11), buffer);
	printf("%d %s\n", strlcat(buffer, str2, 11), buffer);
	return 0;
}
