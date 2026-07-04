#include <stdio.h>
#include <stdlib.h>

void ft_ultimate_div_mod(int *a, int *b);

int main() {
	int a, b, i;
	srand(68109);
	for (i = 0; i < 10000; ++i) {
		a = rand();
		b = rand();
		ft_ultimate_div_mod(&a, &b);
		printf("%d %d\n", a, b);
	}
	return 0;
}
