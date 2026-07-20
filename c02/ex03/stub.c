/** genparam input
 * print "abcdefg\n";
 * print "ABCDEFG\n";
 * print "0123456789\n";
 * for $i (33 .. 126) {
 * 	print chr($i), "\n";
 * }
 */
#include <stdio.h>
#include "common.h"

FUNCTION(int, ft_str_is_numeric, char *str);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d", ft_str_is_numeric(argv[1]));
}