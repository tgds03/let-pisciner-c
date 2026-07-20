/** genparam input
 * for ($i = 0; $i < 16; $i++) {
 * 	print int(rand(256)) - 128, "\n";
 * }
 */
#include "common.h"
#include <stdlib.h>

FUNCTION(void, ft_is_negative, int n);

void test(int argc, char *argv[]) {
	if (argc != 2) {
		printf("you must to give 1 argument");
		return;
	}
	ft_is_negative(atoi(argv[1]));
}