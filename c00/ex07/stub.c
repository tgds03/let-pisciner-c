/** genparam input
 * print "1\n";
 * print "0\n";
 * print "-1\n";
 * print "10\n";
 * print "-10\n";
 * print "214783647\n";
 * print "-214783648\n";
 * for ($i = 0; $i < 10; $i++) {
 * 	print int(rand(256)) - 128, "\n";
 * }
 */
#include "common.h"
#include <stdlib.h>

FUNCTION(void, ft_putnbr, int nb);
void test(int argc, char *argv[]) {
	UNUSED(argc);
	ft_putnbr(atoi(argv[1]));
}