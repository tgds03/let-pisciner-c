/** genparam input
 * for $i (-1 .. 13) {
 * 	print $i;
 * }
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

FUNCTION(int, ft_iterative_factorial, int nb);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d\n", ft_iterative_factorial(atoi(argv[1])));
}
