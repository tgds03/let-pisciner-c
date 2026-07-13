// )#> RANDOMIZE_INPUT int
#include "common.h"
#include <stdio.h>
#include <stdlib.h>

#define RANDOMIZE_INPUT 1
FUNCTION(void, ft_ultimate_ft, int *********nbr);

void nest_pointer(void *ptr) {
	static int level = 9;
	if (level == 1) {
		ft_ultimate_ft(ptr);
	} else {
		level -= 1;
		nest_pointer(&ptr);
		level += 1;
	}
}

void test(int argc, char* argv[]) {
	UNUSED(argc);
	int n = atoi(argv[1]);
	nest_pointer(&n);
	printf("%d", n);
}
