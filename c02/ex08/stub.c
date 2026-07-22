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

FUNCTION(char *, ft_strlowcase, char *str);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%s", ft_strlowcase(argv[1]));
}