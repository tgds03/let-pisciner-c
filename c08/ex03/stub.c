#include <stdlib.h>
#include <stdio.h>
#include "ft_point.h"
#include "common.h"

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

void test(int argc, char *argv[]) {
	UNUSED(argc);
	UNUSED(argv);
	t_point point;
	set_point(&point);
	printf("%d %d", point.x, point.y);
}
