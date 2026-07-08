#include <stdio.h>

int ft_atoi(char *str);

int main()
{
	char *str[12] = {
		"", "1", "0", "-1", 
		"2147483648", "2147483647", "-2147483648", "-2147483649", 
		" \f\n\r\t\v3 1", "\t\v +---+--23", "\r +- -+32", "    +-++\t352"
	};
	for (int i = 0; i < 12; ++i)
	{
		printf("%d\n", ft_atoi(str[i]));
	}
	return 0;
}
