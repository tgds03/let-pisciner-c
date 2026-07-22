/** genparam input
 * print 0;
 * print "1234", "5678", "9012", "3456", ":";
 * print "abcd", "1234", "efgh", "5678", "-";
 * print 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "a", "b", "c", "d", "e", "f", ",";
 * print "AAA", "B", "CCCCC", "DD", "abcde";
 * 
 * $\ = " ";
 * $, = "";
 * for $_ (1 .. 5) {
 * 	$len = int(rand(32));
 * 	for $i (1 .. $len) {
 * 		print printable_random(16);
 * 	}
 * 	print printable_random(16);
 * 	print "\n";
 * }
 */
#include <stdio.h>
#include "common.h"

FUNCTION(char*, ft_strjoin, int size, char **strs, char *sep);

void test(int argc, char *argv[]) {
	char *res;
	res = ft_strjoin(argc - 2, argv + 1, argv[argc - 1]);
	printf("arguments: ");
	for (int i = 1; i < argc; ++i)
		printf("%s ", argv[i]);
	printf("\nresult: %s\n", res);
	printf("free: ");
	if (res)
		free(res);
	printf("done.");
}
