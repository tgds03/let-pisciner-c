/** genparam input
 * print '""';
 * print "1";
 * print "0";
 * print "-1";
 * print "2147483647";
 * print "-2147483648";
 * print '"   123"';
 * print '"\t\n\f-321"';
 * print "--+-+512";
 * print "+--+--1024";
 * print '" \f\n\r\t\v-3 1"';
 * print '"\t\v +---+--23"';
 * print '"\r +- -+32"';
 * print '"    +-++\t352"';
 */
#include <stdio.h>
#include "common.h"

FUNCTION(int, ft_atoi, char *str);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d", ft_atoi(argv[1]));
}