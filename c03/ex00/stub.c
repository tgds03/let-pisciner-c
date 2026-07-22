/** genparam input
 * print "11111", "11111";
 * print "11111", "11112";
 * print "11111", "11110";
 * print "11111", "1111";
 * print "11111", "111111";
 * print "11111", '""';
 * print '"" ""';
 */
#include "common.h"
#include <stdio.h>

FUNCTION(int, ft_strcmp, char *s1, char *s2);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d", ft_strcmp(argv[1], argv[2]));
}