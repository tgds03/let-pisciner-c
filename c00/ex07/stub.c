void ft_putnbr(int nb);

int main() {
	ft_putnbr(~(1<<31));
	ft_putnbr(100);
	ft_putnbr(10);
	ft_putnbr(1);
	ft_putnbr(0);
	ft_putnbr(-1);
	ft_putnbr(-10);
	ft_putnbr(1<<31);
	return 0;
}
