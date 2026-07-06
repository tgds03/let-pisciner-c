#include <stdio.h>
#include <string.h>

int main() {
	char *s1 = "55555";
	char *s2 = "55556";
	char *s3 = "55554";
	char *s4 = "5555";
	char *s5 = "555555";
	printf("%d ", strcmp(s1, s1));
	printf("%d ", strcmp(s1, s2));
	printf("%d ", strcmp(s1, s3));
	printf("%d ", strcmp(s1, s4));
	printf("%d ", strcmp(s1, s5));
	return 0;
}
