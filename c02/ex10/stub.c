/** genparam input
 * print "0\n";
 * print "0 abcde\n";
 * print "5 abcde\n";
 * print "10 abcde\n";
 * print "20 012345678901234567890123456789\n";
 */
#include <stdlib.h>
#include <stdio.h>
#include "common.h"

FUNCTION(unsigned int, ft_strlcpy, char *dest, char *src, unsigned int size);

void fill(char *arr, int size) {
	for (int i = 0; i < size - 1; ++i) {
		arr[i] = '.';
	}
	arr[size - 1] = 0;
}

void test(int argc, char *argv[]) {
	UNUSED(argc);
	char *buffer;
	int n, len = 0;

	n = atoi(argv[1]);
	while (argv[2][len++]);
	buffer = (char*)calloc(len + 1, sizeof(char));
	fill(buffer, len + 1);
	printf("%d %s", (int)ft_strlcpy(buffer, argv[2], n), buffer);
	free(buffer);
}