/** genparam input
 * print "1";
 * print "0";
 * print "-1";
 * print "10";
 * print "-10";
 * print "214783647";
 * print "-214783648";
 * for ($i = 0; $i < 10; $i++) {
 * 	print int(rand(256)) - 128;
 * }
 */
#include "common.h"
#include <stdlib.h>

FUNCTION(void, ft_putnbr, int nb);
void test(int argc, char *argv[]) {
	UNUSED(argc);
	ft_putnbr(atoi(argv[1]));
}