/** genparam input
 * print 0, 0;
 * print 0, 1;
 * print 1, 0;
 * print -10, 10;
 * print 10, -10;
 * for $_ (1.. 10) {
 * 	$start = int(rand(2048)) - 1024;
 * 	$range = int(rand(32)) - 16;
 * 	print $start, $start + $range;
 * }
 */
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
	if (arr) {
		for (int i = 0; i < b - a; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\ncount: %d\n", b - a);
		printf("free: ");
		if (arr)
			free(arr);
		printf("done");
	} else {
		printf("null");
	}
}
