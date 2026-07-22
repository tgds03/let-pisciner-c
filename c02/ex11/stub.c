/** genparam input
 * $, = "";
 * $\ = "";
 * print '"';
 * for $i (1 .. 128) {
 * 	print char($i);
 * }
 * print char(0);
 * print '"';
 */
#include "common.h"

FUNCTION(void, ft_putstr_non_printable, char *str);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	ft_putstr_non_printable(argv[1]);
}