#include "common.h"
#include <stdlib.h>

FUNCTION(void, ft_print_combn, int n);
void test(int argc, char *argv[]) {
	if (argc != 2) {
		printf("you must to give 1 argument");
		return;
	}
	ft_print_combn(atoi(argv[1]));
}
