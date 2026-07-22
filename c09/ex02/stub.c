/** genparam input
 * print '""', "a";
 * print "aaaaaaaaaa", '""';
 * print "aaaaaaaaaa", "a";
 * print "aaa33", "a";
 * print "aaaa33aaa22", "a";
 * print "44aaaaa", "a";
 * print "55a6666aa", "a";
 * print "aabbbaacccaaadda", "a";
 * print "Loremipsum^dolor*sitame!tconsecte#turadipiscinge%lit", "!@#$%^&*()";
 * print "LoremPipsumXdolorQsitBamet,RconsecteturIadipiscingKelit", "PXQBRIK";
 */
#include <stdio.h>
#include "common.h"

FUNCTION(char**, ft_split, char *str, char *charset);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	char **res, **cur;
	res = ft_split(argv[1], argv[2]);
	cur = res;
	while (*cur) {
		if (argv[1] <= *cur && *cur < argv[2]) {
			printf("F ");
		} else {
			printf("P ");
		}
		printf("%s\n", *cur);
		free(*cur);
		++cur;
	}
	free(res);
}
