/** genparam input
 * print "hi, hOw ArE yOu? 42words forty-two;fifty_and+one\0siX-SeVen\n";
 * print "aaa Aaa aAa aaA AAa AaA aAA AAA\n";
 * print "0Aa 0aA a0A A0a Aa0 aA0\n";
 * 
 * $alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
 * $alphanum = length($alphabet);
 * for $_ (0 .. 10) {
 * 	$len = int(rand(32));
 * 	for $i (0 .. $len) {
 * 		print substr($alphabet, int(rand($alphanum)), 1);
 * 	}
 * 	print "\n";
 * }
 */
#include <stdio.h>
#include "common.h"

FUNCTION(char *, ft_strcapitalize, char *str);

void test(int argc, char *argv[]) {
	UNUSED(argc);
	printf("%s", ft_strcapitalize(argv[1]));
}