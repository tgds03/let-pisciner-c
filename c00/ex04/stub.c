#include "common.h"
#include <stdlib.h>

FUNCTION(void, ft_is_negative, int n);

void test(int argc, char *argv[]) {
	if (argc != 2) {
		printf("you must to give 1 argument");
		return;
	}
	ft_is_negative(atoi(argv[1]));
}

/**
int main() {
	ft_is_negative(~(1<<31));
	ft_is_negative(1);
	ft_is_negative(0);
	ft_is_negative(-1);
	ft_is_negative(1<<31);

	init_rand(__FILE__);
	for (int i = 0; i < 10; ++i) {
		ft_is_negative(rand());
	}
	return 0;
}
**/
