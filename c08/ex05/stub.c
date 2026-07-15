// genparam>> SET_INPUT
// genparam>> SET_INPUT a
// genparam>> SET_INPUT 1 2 3 4
// genparam>> SET_INPUT a b c d
// genparam>> REPEAT 3 RANDOMIZE_INPUT str str str
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "ft_stock_str.h"

FUNCTION(void, ft_show_tab, struct s_stock_str *par);

struct s_stock_str* ft_strs_to_tab(int ac, char **av);

void test(int argc, char *argv[]) {
	struct s_stock_str *arr = ft_strs_to_tab(ac - 1, av + 1);
	ft_show_tab(arr);
}
