/** genparam input
 * print "";
 * print '""';
 * print "a";
 * print 1, 2, 3, 4;
 * print "a", "b", "c", "d";
 * $\ = "";
 * $, = "";
 * for $_ (1 .. 5) {
 * 	$len = int(rand(28) + 4);
 * 	for $i (1 .. $len) {
 * 		print printable_random(16), " ";
 * 	}
 * 	print "\n";
 * }
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "ft_stock_str.h"

FUNCTION(void, ft_show_tab, struct s_stock_str *par);

struct s_stock_str* ft_strs_to_tab(int ac, char **av);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	UNUSED(argv);
	struct s_stock_str *arr = ft_strs_to_tab(argc - 1, argv + 1);
	struct s_stock_str *cur = arr;

	ft_show_tab(arr);
	while (cur->str) {
		free(cur->copy);
		++cur;
	}
	free(arr);
}
