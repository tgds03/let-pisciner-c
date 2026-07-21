/** genparam input
 * print '0 "Hello world!"';
 * print '3 "Hello world!"';
 * print '7 "Hello world!"';
 * print '12 "Hello world!"';
 * print '7 "abcde\0abcde"';
 * $\ = "";
 * $, = "";
 * for $_ (0 .. 10) {
 * 	$len = int(rand(16));
 * 	$n = int(rand($len));
 * 	print $n, " ", '"';
 * 	for $i (0 .. $len) {
 * 		print char(int(rand(95)) + 32);
 * 	}
 * 	print '"', "\n";
 * }
 */
#include <stdio.h>
#include "common.h"

FUNCTION(char *, ft_strncpy, char *dest, char *src, unsigned int n);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	char *buf;
	int n, len = 0;
	n = atoi(argv[1]);
	while (argv[2][len++]);
	buf = (char*)calloc(len + 1, sizeof(char));
	ft_strncpy(buf, argv[2], n);
	printf("%s\n", buf);
	free(buf);
}