#include <stdio.h>
#include <stdlib.h>

void ft_swap(int *a, int *b);

int main() {
	int a, b, i;
	srand(9988);
	for (i = 0; i < 10000; ++i) {
		a = rand();
		b = rand();
		ft_swap(&a, &b);
		printf("%d %d\n", a, b);
	}
	return 0;
}
