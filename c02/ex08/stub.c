#include <stdio.h>

char *ft_strlowcase(char *str);

int main() {
	char a[96];
	for (int i = 0; i < 95; ++i) {
		a[i] = 32 + (char)i;
	}
	a[95] = 0;
	printf("%s", ft_strlowcase(a));
	return 0;
}
