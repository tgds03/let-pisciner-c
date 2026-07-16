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
	struct s_stock_str *tab = ft_strs_to_tab(argc - 1, argv + 1);
	struct s_stock_str *cur = tab;
	int i = 0;
	while (cur->str) {
		printf("element %d\n", i++);
		printf("size: %d\n", cur->size);
		printf(" str: %s\n", cur->str);
		printf("copy: %s\n", cur->copy);
		printf("pointer of str and copy are ");
		if (cur->str == cur->copy) {
			printf("same.\n");
		} else {
			printf("not same.\n");
		}
		free(cur->copy);
		++cur;
		printf("\n");
	}
	free(tab);
}
