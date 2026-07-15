// genparam>> SET_INPUT 0
// genparam>> SET_INPUT abcd 1234 efgh 5678 ijkl 9012 .
// genparam>> SET_INPUT 0 1 2 3 4 5 6 7 8 9 a b c d e f -
// genparam>> REPEAT 5 RANDOMIZE_INPUT str str str str str str
#include <stdio.h>
#include "common.h"

FUNCTION(char*, ft_strjoin, int size, char **strs, char *sep);

void test(int argc, char *argv[]) {
	char *res;
	res = ft_strjoin(argc - 2, argv + 1, argv[argc - 1]);
	for (int i = 1; i < argc; ++i)
		printf("%s ", argv[i]);
	printf("\n%s\n", res);
	printf("free: ");
	free(res);
	printf("done.");
}
