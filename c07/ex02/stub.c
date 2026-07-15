// genparam>> SET_INPUT 0 0
// genparam>> SET_INPUT 0 1
// genparam>> SET_INPUT 1 0
// genparam>> SET_INPUT -10 10
// genparam>> SET_INPUT 10 -10
// genparam>> REPEAT 10 RANDOMIZE_INPUT int int

#include <stdlib.h>
#include <stdio.h>
#include "common.h"

FUNCTION(int, ft_ultimate_range, int **range, int min, int max);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	int *arr;
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int t, s;

	s = ft_ultimate_range(&arr, a, b);
	for (int i = 0; i < s; ++i) {
		printf("%d ", arr[i]);
	}
	t = (b > a) ? b - a : 0;
	printf("\nexpected count: %d, retunred count: %d\n", t, s); 
	printf("free: ");
	if (arr)
		free(arr);
	printf("done");
}
