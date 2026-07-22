/** genparam input
 * print "0123456789", '01234\056789', '""';
 * print "0123456789", '01234\056789', '""', "0123456789", '01234\056789', '""', 'a';
 * print "abcdefg", "hijklmn", "opqrstu";
 * print '" "', '"\t"', '""', '"\t"';
 */
#include <stdio.h>
#include "common.h"

FUNCTION(char*, ft_strcat, char *dest, char *src);

void test(int argc, char *argv[]) {
	char buffer[1024];
	for (int i = 1; i < argc; ++i) {
		printf("%s\n", ft_strcat(buffer, argv[i]));
	}
}