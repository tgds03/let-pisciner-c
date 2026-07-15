// genparam>> SET_INPUT 0
// genparam>> SET_INPUT abcdefghijklmnopqrstuvwxyz
// genparam>> REPEAT 10 RANDOMIZE_INPUT str

#include <stdio.h>
#include "common.h"

FUNCTION(char*, ft_strdup, char *src);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	char *dup;
	dup = ft_strdup(argv[1]);
	printf("%s\n", dup);
	printf("argv[1] and return of ft_strdup are ");
	if (dup == argv[1]) {
		printf("same.\n");
	} else {
		printf("not same.\n");
	}
}
