/** genparam input
 * for $i (0 .. 10) {
 * 	print int(rand(256)) - 128, " ", int(rand(256)) - 128, "\n";
 * }
 */
#include <stdio.h>
#include "common.h"

FUNCTION(void, ft_ultimate_div_mod, int *a, int *b);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	int a, b;
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	ft_ultimate_div_mod(&a, &b);
	printf("%d %d", a, b);
}
