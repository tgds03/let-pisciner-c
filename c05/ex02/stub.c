/** genparam input
 * print -1, -1;
 * print 0, -1;
 * print -1, 0;
 * print 0, 0;
 * print 0, 1;
 * print 0, 2;
 * print 0, 5;
 * for $i (1 .. 5) {
 * 	for $j (-1 .. 5) {
 * 		if ($i % 2 != 0) {
 * 			print -1 * $i, $j;
 * 		} else {
 * 			print $i, $j;
 * 		}
 * 	}
 * }
 * print -12, 3;
 * print 42, 21;
 * print 10, 9;
 * print 10, 10;
 * print -10, 9;
 * print -10, 11;
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

FUNCTION(int, ft_iterative_power, int nb, int power);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d\n", ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
}
