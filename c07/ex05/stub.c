// genparam>> SET_INPUT aaaaaaaaaa a
// genparam>> SET_INPUT Loremipsum^dolor*sitame!tconsecte#turadipiscinge%lit !@#$%^&*()
// genparam>> SET_INPUT LoremPipsumXdolorQsitBamet,RconsecteturIadipiscingKelit PXQBRIK
#include <stdio.h>
#include "common.h"

FUNCTION(char**, ft_split, char *str, char *charset);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	char **res;
	res = ft_split(argv[1], argv[2]);
	printf("%s %s\n", argv[1], argv[2]);
	while (**res) {
		if (argv[1] <= *res && *res < argv[2]) {
			printf("1 ");
		} else {
			printf("0 ");
		}
		printf("%s\n", *res);
		++res;
	}
}
