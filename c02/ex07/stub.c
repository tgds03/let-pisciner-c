#include <stdio.h>

char *ft_strupcase(char *str);

int main() {
	char a[96];
	for (int i = 0; i < 95; ++i) {
		a[i] = 32 + (char)i;
	}
	a[95] = 0;
	printf("%s", ft_strupcase(a));
	return 0;
}
