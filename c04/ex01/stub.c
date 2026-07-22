/** genparam input
 * print 'abcdefg\nhijklmn';
 * print printable_inline();
 */
#include "common.h"

FUNCTION(void, ft_putstr, char *str);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	ft_putstr(argv[1]);
}