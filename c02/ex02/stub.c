/** genparam input
 * print "abcdefg";
 * print "ABCDEFG";
 * print "0123456789";
 * $\ = "";
 * print '"';
 * for $i (32 .. 126) {
 * 	print char($i);
 * }
 * print "\"\n";
 */
#include <stdio.h>
#include "common.h"

FUNCTION(int, ft_str_is_alpha, char *str);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d", ft_str_is_alpha(argv[1]));
}