/** genparam input
 * print "0123456789", '0', '01234\056789', '1', '""', '2';
 * print "0123456789", '11', '01234\056789', '12', '""', '13';
 * print "0123456789", '3', '01234\056789', '5', '""', '1', "0123456789", '10', '01234\056789', '6', '""', '0', 'a', '1';
 * print "abcdefg", '7', "hijklmn", '7', "opqrstu", '7';
 * print '" "', '1', '"	"', '1', '""', '1', '" "', '1';
 */
#include <string.h>
#include <stdio.h>
#include "common.h"

FUNCTION(unsigned int, ft_strlcat, char *dest, char *src, unsigned int size);

void test(int argc, char *argv[]) {
	char buffer[81];
	char *cur;
	int num;

	for (int i = 0; i < 81; ++i) {
		buffer[i] = 0;
	}

	for (int i = 1; i < argc;) {
		cur = argv[i++];
		num = atoi(argv[i++]);
		printf("%d %s\n", ft_strlcat(buffer, cur, (unsigned int)num), buffer);
	}
}