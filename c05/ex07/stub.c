/** genparam input
 * for $i (-1 .. 100) {
 * 	print $i;
 * }
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

FUNCTION(int, ft_find_next_prime, int nb);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d\n", ft_find_next_prime(atoi(argv[1])));
}
