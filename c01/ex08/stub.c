/** genparam input
 * print "0 1 2 3 4 5 6 7 8 9";
 * print "9 8 7 6 5 4 3 2 1 0";
 * print "1 2 3 4 5 6 7 8 9 0";
 * print "8 7 6 5 4 3 2 1 0 9";
 * print "0 3 3 2 1 3 1 1 2 0";
 * $, = "";
 * $\ = "";
 * for $_ (0 .. 20) {
 * 	$len = int(rand(16));
 * 	for $i (0 .. $len) {
 * 		print int(rand(256)) - 128, " ";
 * 	}
 * 	print "\n";
 * }
 */
#include <stdio.h>
#include "common.h"

FUNCTION(void, ft_sort_int_tab, int *tab, int size);

void test(int argc, char *argv[]) {
	int arr[256];
	int size = argc - 1;
	if (size > 256)
		size = 256;
	for (int i = 0; i < size; ++i) {
		arr[i] = atoi(argv[i + 1]);
	}
	ft_sort_int_tab(arr, size);
	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
}