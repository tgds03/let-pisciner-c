/** genparam input
 * print '""';
 * print "0123456789";
 * print 'abcdefghij\0klmnopqrst';
 */
#include <stdio.h>
#include "common.h"

FUNCTION(int, ft_strlen, char *str);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d", ft_strlen(argv[1]));
}