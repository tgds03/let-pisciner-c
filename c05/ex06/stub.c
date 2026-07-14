#include <stdio.h>
#include <stdlib.h>
#include "common.h"

FUNCTION(int, ft_is_prime, int nb);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d\n", ft_is_prime(atoi(argv[1])));
}
