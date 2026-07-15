// genparam>> SET_INPUT
// genparam>> SET_INPUT a
// genparam>> SET_INPUT 1 2 3 4
// genparam>> SET_INPUT a b c d
// genparam>> REPEAT 3 RANDOMIZE_INPUT str str str
#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"
#include "common.h"

FUNCTION(struct s_stock_str*, ft_strs_to_tab, int ac, char **av);

void test(int argc, char *argv[]) {
	struct s_stock_str *cur = ft_strs_to_tab(ac - 1, av + 1);
	int i = 0;
	while (cur->str) {
		printf("element %d\n", i++);
		printf("size: %d\n", cur->size);
		printf(" str: (%p)%s\n", &(cur->str), cur->str);
		printf("copy: (%p)%s\n", &(cur->copy), cur->copy);
		printf("\n");
	}
}
