/** genparam input
 * @values = (2147483647, 100, 10, 1, 0, -1, -10, -2147483648);
 * print 1234, '""';
 * print 1234, 0;
 * for $value (@values) {
 * 	print $value, '01';
 * 	print $value, '0123456';
 * 	print $value, '0123456789';
 * 	print $value, '0123456789abc';
 * 	print $value, '0123456789abcdef';
 * 	print $value, 'quite';
 * 	print $value, 'ecol4210';
 * }
 */
#include <stdlib.h>
#include "common.h"

FUNCTION(void, ft_putnbr_base, int nbr, char *base);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	ft_putnbr_base(atoi(argv[1]), argv[2]);
}