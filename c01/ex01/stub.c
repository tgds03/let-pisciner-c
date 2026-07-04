#include <stdio.h>

void ft_ultimate_ft(int *********nbr);

void test(void *ptr) {
	static int level = 9;
	if (level == 1) {
		ft_ultimate_ft(ptr);
	} else {
		level -= 1;
		test(&ptr);
	}
}

int main() {
	int n = -12345;
	test(&n);
	printf("%d", n);
	return 0;
}
