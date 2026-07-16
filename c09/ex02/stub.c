// genparam>> SET_INPUT aaaaaaaaaa a
// genparam>> SET_INPUT aaa33 a
// genparam>> SET_INPUT aabbbaacccaaadda a
// genparam>> SET_INPUT Loremipsum^dolor*sitame!tconsecte#turadipiscinge%lit !@#$%^&*()
// genparam>> SET_INPUT LoremPipsumXdolorQsitBamet,RconsecteturIadipiscingKelit PXQBRIK
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
			printf("1 ");
		} else {
			printf("0 ");
		}
		printf("%s\n", *cur);
		free(*cur);
		++cur;
	}
	free(res);
}
