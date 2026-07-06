#include <stdio.h>
#include <stdlib.h>

void ft_rev_int_tab(int *tab, int size);

int main() {
	int a, b, t;
	int i, j;
	int arr[256];
	srand(584939);
	for (i = 0; i < 256; ++i) {
		arr[i] = rand();
	}
	for (i = 0; i < 100; ++i) {
		a = rand() % 256;
		b = rand() % 256;
		if (a > b) {
			t = a; a = b; b = t;
		}
		ft_rev_int_tab(arr + a, b - a);
		for (j = 0; j < 256; ++j) {
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
	return 0;
}
