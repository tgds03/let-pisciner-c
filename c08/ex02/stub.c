/** genparam input
 * print 2147483647;
 * print 100;
 * print 10;
 * print 1;
 * print 0;
 * print -1;
 * print -10;
 * print -2147483648;
 * for $_ (1 .. 5) {
 * 	print int(rand(65536) - 32768);
 * }
 */
#include <stdlib.h>
#include <stdio.h>
#include "ft_abs.h"
#include "common.h"

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d", ABS(atoi(argv[1])));
}
