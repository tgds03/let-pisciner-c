/** genparam input
 * for $i (0 .. 10) {
 * 	print $i, "\n";
 * }
 */
#include "common.h"
#include <stdio.h>
#include <stdlib.h>

FUNCTION(void, ft_ft, int *nbr);

void test(int argc, char* argv[]) {
	UNUSED(argc);
	int n = atoi(argv[1]);
	ft_ft(&n);
	printf("%d", n);
}
