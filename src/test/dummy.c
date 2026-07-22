#include <stdio.h>
#include "common.h"

FUNCTION(void, ft_dummy) {
    printf("This is test\n");
}

void test(int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);
}