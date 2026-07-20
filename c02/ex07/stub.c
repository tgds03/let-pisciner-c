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

FUNCTION(char *, ft_strupcase, char *str);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%s", ft_strupcase(argv[1]));
}