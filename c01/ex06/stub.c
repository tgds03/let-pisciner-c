/** genparam input
 * print "\n";
 * print "a\n";
 * print "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
 * print "abcdeabcd\nabcdeabcde\tbcdeabcdeabc\0eabcdeabcdeabcde\n";
 */
#include "common.h"
#include <stdio.h>

FUNCTION(int, ft_strlen, char *str);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d", ft_strlen(argv[1]));
}