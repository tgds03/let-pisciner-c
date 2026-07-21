/** genparam input
 * $\ = "";
 * $, = "";
 * for $i (1 .. 16) {
 * 	for $j (1 .. $i) {
 * 		print $j, " ";
 * 	}
 * 	print "\n";
 * }
 */
#include <unistd.h>
#include "ft_boolean.h"
#include "common.h"

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_bool ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

void test(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
}
