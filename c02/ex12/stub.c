const int test1 = 0b01010101010101010101010101010101;
const int test2 = 0;
const int test3 = ~0;
const int test4 = 0b10101010101010101010101010101010;

void *ft_print_memory(void *addr, unsigned int size);

int main() {
	ft_print_memory((void *)&test1, 128);
	return 0;
}
