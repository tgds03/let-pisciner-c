// genparam>> SET_INPUT 0 0 01
// genparam>> SET_INPUT 0 0123457789 0123456789abcdef
// genparam>> SET_INPUT 0 0123457789 0123456789abbdef
// genparam>> SET_INPUT 0 0123456789 0123456789abcdef-
// genparam>> SET_INPUT 0 0123456789+ 0123456789abcdef
// genparam>> SET_INPUT x 0123456789 0123456789abcdef
// genparam>> SET_INPUT 10 0123456789 0123456789abcdef
// genparam>> SET_INPUT -10 0123456789 0123456789abcdef
// genparam>> SET_INPUT 2147483647 0123456789 01
// genparam>> SET_INPUT 2147483648 0123456789 01234567
// genparam>> SET_INPUT -2147483648 0123456789 01
// genparam>> SET_INPUT -2147483649 0123456789 0123456789abcdef
// genparam>> SET_INPUT 12345 0123456789 0123456789
// genparam>> SET_INPUT 21845 0123456789 0123456789abcdef
// genparam>> SET_INPUT 499602D2 0123456789ABCDEF jabcdefghi
// genparam>> SET_INPUT .__._.____._..__ ._ icant2hsprogmue
// genparam>> SET_INPUT 9x81P3 0123456789JumblingVextFrowzyHacksPDQ CwmFjordVegBalksNthPyxQuiz

#include <stdio.h>
#include "common.h"

FUNCTION(char*, ft_convert_base, char *nbr, char *base_from, char *base_to);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	char *res = ft_convert_base(argv[1], argv[2], argv[3]);
	if (res)
		printf("%s\n", res);
	else
		printf("NULL\n");
	printf("free: ");
	if (res)
		free(res);
	printf("done");
}
