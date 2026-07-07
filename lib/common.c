#include <stdlib.h>

void init_rand(char *str) {
	unsigned int seed = 0;
	while (*str != 0) {
		seed += *str;
		++str;
	}
	srand(seed);
}
