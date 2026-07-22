/** genparam input
 * print "2147483647";
 * print "100";
 * print "10";
 * print "1";
 * print "0";
 * print "-1";
 * print "-10";
 * print "-2147483648";
 * for $_ (0 .. 5) {
 * 	print int(rand(256)) - 128;
 * }
 */
#include <stdlib.h>
#include "common.h"

FUNCTION(void, ft_putnbr, int nb);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d", atoi(argv[1]));
}