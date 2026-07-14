#include <stdio.h>
#include <stdlib.h>
#include "common.h"

FUNCTION(int, ft_recursive_power, int nb, int power);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d\n", ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
}
