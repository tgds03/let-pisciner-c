#include "common.h"

void ft_is_negative(int n);

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
