static char target[128] = " 012345678901234567890123456789 !! You should see this if this program show memory correctly !! 987654321098765432109876543210 ";

void *ft_print_memory(void *addr, unsigned int size);

int main() {
	ft_print_memory((void *)&target, 128);
	return 0;
}
