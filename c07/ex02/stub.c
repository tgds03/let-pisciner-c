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
