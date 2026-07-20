/** genparam input
 * print "Hello_world!\n";
 * print "abcde\0abcde";
 * for $_ (0 .. 10) {
 * 	$len = int(rand(16));
 * 	for $i (0 .. $len) {
 * 		print chr(int(rand(95)) + 33);
 * 	}
 * 	print "\n";
 * }
 */
#include <stdlib.h>
#include <stdio.h>
#include "common.h"

FUNCTION(char *, ft_strcpy, char *dest, char *src);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	char *buf;
	int len = 0;
	while (argv[1][len++]);
	buf = (char*)calloc(len, sizeof(char));
	ft_strcpy(buf, argv[1]);
	printf("%s\n", buf);
	free(buf);
}