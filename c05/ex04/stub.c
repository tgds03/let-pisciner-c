#include <stdio.h>
#include <stdlib.h>
#include "common.h"

FUNCTION(int, ft_fibonacci, int index);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%d\n", ft_fibonacci(atoi(argv[1])));
}
