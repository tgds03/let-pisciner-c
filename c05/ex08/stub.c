#include <stdio.h>
#include "common.h"

FUNCTION(int, ft_ten_queens_puzzle);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	UNUSED(argv);
	printf("%d\n", ft_ten_queens_puzzle());
}

