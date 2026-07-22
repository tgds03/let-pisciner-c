/** genparam input
 * for ($i = 1; $i < 10; $i++) {
 * 	print $i;
 * }
 */
#include "common.h"
#include <stdlib.h>

FUNCTION(void, ft_print_combn, int n);
void test(int argc, char *argv[]) {
	UNUSED(argc);
	ft_print_combn(atoi(argv[1]));
}
