#include <stdio.h>

int ft_strlen(char *str);

int main() {
	char *s1 = "";
	char *s2 = "a";
	char *s3 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char *s4 = "abcdeabcd\nabcdeabcde\tbcdeabcdeabc\0eabcdeabcdeabcde";
	printf("%d %d %d %d",
		ft_strlen(s1),
		ft_strlen(s2),
		ft_strlen(s3),
		ft_strlen(s4)
	);
	return 0;
}
