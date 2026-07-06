void ft_putstr_non_printable(char *str);

int main() {
	char str[128];
	for (int i = 0; i < 127; ++i) {
		str[i] = i + 1;
	}
	str[127] = 0;
	ft_putstr_non_printable(str);
	return 0;
}
