// genparam>> REPEAT 10 RANDOMIZE_INPUT int int int int int int int int
#include <stdio.h>
#include "common.h"

#define RANDOMIZE_INPUT 16
FUNCTION(void, ft_sort_int_tab, int *tab, int size);

void test(int argc, char *argv[]) {
	int arr[256];
	int size = argc;
	if (size > 256)
		size = 256;
	for (int i = 1; i < size + 1; ++i) {
		arr[i - 1] = atoi(argv[i]);
	}
	ft_rev_int_tab(arr, size);
	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
}

/*
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
*/
