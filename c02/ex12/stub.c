#include "common.h"

FUNCTION(void *, ft_print_memory, void *addr, unsigned int size);

static char target[128] = " 012345678901234567890123456789 !! You should see this if this program show memory correctly !! 987654321098765432109876543210 ";

void test(int argc, char *argv[]) {
	UNUSED(argc);
	UNUSED(argv);
	ft_print_memory((void *)&target, 128);
}