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
