/** genparam input
 * print "0123456789", "0123";
 * print "0123456789", "789";
 * print "0123456789", "3456";
 * print "0123456789", '""';
 * print '""', '""';
 * print '""', "0123456789";
 * print "0123", "789";
 * print "01201234", "01234";
 * print "11121231234", "123";
 */
#include <stdio.h>
#include "common.h"

FUNCTION(char*, ft_strstr, char *str, char *to_find);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%s", ft_strstr(argv[1], argv[2]));
}