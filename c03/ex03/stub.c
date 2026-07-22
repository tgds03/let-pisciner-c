/** genparam input
 * print "0123456789", '0', '01234\056789', '1', '""', '2';
 * print "0123456789", '11', '01234\056789', '12', '""', '13';
 * print "0123456789", '3', '01234\056789', '5', '""', '1', "0123456789", '10', '01234\056789', '6', '""', '0', 'a', '1';
 * print "abcdefg", '7', "hijklmn", '7', "opqrstu", '7';
 * print '" "', '1', '"\t"', '1', '""', '1', '"\t"', '1';
 */
#include <stdio.h>
#include "common.h"

FUNCTION(char *, ft_strncat, char *dest, char *src, unsigned int nb);
void test(int argc, char *argv[]) {
	char buffer[1024];
	char *cur;
	int num;
	for (int i = 1; i < argc;) {
		cur = argv[i++];
		num = atoi(argv[i++]);
		printf("%s\n", ft_strncat(buffer, cur, num));
	}
}