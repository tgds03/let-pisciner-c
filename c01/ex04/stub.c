#include <stdio.h>
#include "common.h"

void ft_ultimate_div_mod(int *a, int *b);

int main() {
	int a, b, i;
	init_rand(__FILE__);
	for (i = 0; i < 10000; ++i) {
		a = rand();
		b = rand();
		ft_ultimate_div_mod(&a, &b);
		printf("%d %d\n", a, b);
	}
	return 0;
}
