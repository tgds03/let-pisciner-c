#include <stdio.h>
#include "common.h"

void ft_sort_int_tab(int *tab, int size);

int main() {
	int i, j;
	int arr[16];
	init_rand(__FILE__);
	for (i = 0; i < 100; ++i) {
		for (j = 0; j < 16; ++j) {
			arr[j] = rand() % 1000;
		}
		ft_sort_int_tab(arr, 16);
		for (j = 0; j < 16; ++j) {
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
	return 0;
}
