unsigned int write(int files, const void *buf, unsigned int nbyute);
void ft_print_combn(int n);

int main() {
	for (int i = 1; i < 9; ++i) {
		ft_print_combn(i);
		write(1, "\n", 1);
	}
	return 0;
}
