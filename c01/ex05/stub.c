void ft_putstr(char *str);

int main() {
	int k = 0;
	char a[200];
	for (int i = 32; i < 127; ++i) {
		a[k++] = i;
	}
	a[k++] = '0';
	for (int i = 32; i < 127; ++i) {
		a[k++] = i;
	}
	a[k++] = '0';
	ft_putstr(a);
	return 0;
}
