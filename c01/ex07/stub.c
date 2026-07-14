// genparam>> REPEAT 10 RANDOMIZE_INPUT int int int int int int int int
#include <stdio.h>
#include "common.h"

FUNCTION(void, ft_rev_int_tab, int *tab, int size);

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
*/
