/** genparam input
 * print "Hello world";
 * $\ = "";
 * $, = "";
 * print '"';
 * for $i (32 .. 126) {
 * 	print char($i);
 * }
 * print "\"\n";
 */
#include "common.h"

FUNCTION(void, ft_putstr, char *str);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	ft_putstr(argv[1]);
}
