/** genparam input
 * for $i (0 .. 4) {
 * 	print '55 ""', $i;
 * 	print '55 55', $i;
 * 	print '55 56', $i;
 * 	print '55 54', $i;
 * 	print '55 5', $i;
 * 	print '55 555', $i;
 * }
 */
#include <stdlib.h>
#include <stdio.h>
#include "common.h"

FUNCTION(int, ft_strncmp, char *s1, char *s2, unsigned int n);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d", ft_strncmp(argv[1], argv[2], (unsigned int)atoi(argv[3])));
}