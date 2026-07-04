#include <stdio.h>
#include <stdlib.h>

void ft_div_mod(int a, int b, int *div, int *mod);

int main() {
	int a, b, div, mod, i;
	srand(6292);
	for (i = 0; i < 10000; ++i) {
		a = rand();
		b = rand();
		ft_div_mod(a, b, &div, &mod);
		printf("%d %d\n", div, mod);
	}
	return 0;
}
