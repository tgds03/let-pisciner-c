/** genparam input
 * print 1234, '""';
 * print 1234, '0';
 * print '""', '0123456789';
 * print 1, '0123456789';
 * print 'x', '0123456789';
 * print 0, '0123456789';
 * print -1, '0123456789';
 * print 2147483647, '0123456789';
 * print -2147483648, '0123456789';
 * print 21845, '0123456789abcdef';
 * print "11000000111001", "01";
 * print "499602D2", "0123456789ABCDEF";
 * print '" \f\n\r\t\v+--+499602D2"', "0123456789ABCDEF";
 * print "--+-.__._.___._..__", "._";
 * print "9x81P3", "0123456789JumblingVextFrowzyHacksPDQ";
 * print '"--+\f\v +--+9x81P3"', "0123456789JumblingVextFrowzyHacksPDQ";
 */
#include <stdio.h>
#include "common.h"

FUNCTION(int, ft_atoi_base, char *str, char *base);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d", ft_atoi_base(argv[1], argv[2]));
}
