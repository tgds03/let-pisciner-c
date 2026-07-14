#include <stdio.h>
#include <stdlib.h>
#include "common.h"

FUNCTION(int, ft_recursive_factorial, int nb);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d\n", ft_recursive_factorial(atoi(argv[1])));
}
