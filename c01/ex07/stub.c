#include <stdio.h>
#include "common.h"

void ft_rev_int_tab(int *tab, int size);

int main() {
	int a, b, t;
	int i, j;
	int arr[256];
	init_rand(__FILE__);
	for (i = 0; i < 16; ++i) {
		arr[i] = rand() % 1024;
	}
	for (i = 0; i < 100; ++i) {
		a = rand() % 16;
		b = rand() % 16;
		if (a > b) {
			t = a; a = b; b = t;
		}
		ft_rev_int_tab(arr + a, b - a);
		for (j = 0; j < 16; ++j) {
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
	return 0;
}
