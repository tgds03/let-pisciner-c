#include <stdio.h>
#include <stdlib.h>
#include "common.h"

FUNCTION(int, ft_iterative_power, int power);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d\n", ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
}
