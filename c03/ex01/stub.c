#include <stdio.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main() {
	char *s0 = "";
	char *s1 = "55";
	char *s2 = "56";
	char *s3 = "54";
	char *s4 = "5";
	char *s5 = "555";

	for (int n = 0; n <= 3; ++n) {
		printf("%d ", ft_strncmp(s1, s0, n));
		printf("%d ", ft_strncmp(s1, s1, n));
		printf("%d ", ft_strncmp(s1, s2, n));
		printf("%d ", ft_strncmp(s1, s3, n));
		printf("%d ", ft_strncmp(s1, s4, n));
		printf("%d ", ft_strncmp(s1, s5, n));
	}
	return 0;
}
