// genparam>> SET_INPUT 0 0
// genparam>> SET_INPUT 0 1
// genparam>> SET_INPUT 1 0
// genparam>> SET_INPUT -10 10
// genparam>> SET_INPUT 10 -10
// genparam>> REPEAT 10 RANDOMIZE_INPUT int int

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

FUNCTION(int*, ft_range, int min, int max);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int t;
	int *arr = ft_range(a, b);

	if (a > b) {
		t = a;
		a = b;
		b = t;
	}
	for (int i = 0; i < b - a; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n%d", b - a);
}
