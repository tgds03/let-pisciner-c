#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>
#include "common.h"

const char *HEX_DIGIT = "0123456789ABCDEF";
const char *FALLBACK_CHAR[32] = {
	0, 0, 0, 0, 0, 0, 0, "\\a", 
	"\\b", "\\t", "\\n", "\\v", "\\f", "\\r", 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0 
};
FunctionEnv function_env;

void init_rand(const char *str) {
	unsigned int seed = 0;
	char *buffer = strdup(str);
	char *bname = basename(buffer);
	while (*bname != 0) {
		seed += *bname;
		++bname;
	}
	srand(seed);
	free(buffer);
}

void putstr_raw(const char *str, unsigned int size) {
	unsigned int count = 0;
	while (*str && count++ < size) {
		if (isprint(*str)) {
			write(1, str, 1);
		} else {
			if (*str < 32 && FALLBACK_CHAR[(int)*str] != 0) {
				write(1, FALLBACK_CHAR[(int)*str], 2);
			} else {
				write(1, "\\", 1);
				write(1, HEX_DIGIT + *str / 16, 1);
				write(1, HEX_DIGIT + *str % 16, 1);
			}
		}
		++str;
	}
}

void randstr(char *str, unsigned int size, const char *charset) {
	const unsigned int numset = strlen(charset);
	while (size--) {
		*(str++) = charset[rand() % numset];
	}
	*str = 0;
}

/**
#define MAX_ARGNUM 16
Param* convert(const char* argstr) {
	char *token[MAX_ARGNUM] = {0, };
	int token_len[MAX_ARGNUM] = {0, };
	char *token_start = argstr;
	int depth = 0, count = 0;
	char *cur = argstr;
	
	while (*cur) {
		if (*cur == '(' || *cur == '[')
			++depth;
		else if (*cur == ')' || *cur == ']')
			--depth;
		else if (*cur == ',' && depth == 0) {
			if (count >= MAX_ARGNUM - 1) {
				break;
			}
			token_len[count] = (int)(cur - token_start);
			token[count] = token_start;
			token_start = cur + 1;
			++count;
		}
		++cur;
	}
}
**/

#define LINE_BUFFER_SIZE 256
char func_header[LINE_BUFFER_SIZE];

void handle_signal(int sig) {
	printf("\nReceived signal %d", sig);
	exit(0);
}

void init_test() {
	init_rand(function_env.stubmd5);
	signal(2, handle_signal); // interrupt
	signal(3, handle_signal); // quit
	signal(11, handle_signal); // segmentation fault
	signal(15, handle_signal); // terminated
	snprintf(func_header,
			LINE_BUFFER_SIZE,
			"%s %s(%s);",
			function_env.type,
			function_env.name,
			function_env.param
	);
	printf("%32c", '='); printf(" Let Pisciner C "); printf("%32c\n", '=');
	printf("Compiled: %s\n", function_env.path);
	printf("Function: %s\n", func_header);
	printf("%80c\n", '=');
	printf("Press Ctrl + C to interrupt and exit.");
}

void loop_test(void (*callback)(int, char*[])) {
	const char* WHITESPACE = " \x09\x0a\x0b\x0c\x0d";
	char input_buffer[LINE_BUFFER_SIZE];
	char *argv[LINE_BUFFER_SIZE], *cur;
	int argc = 1;

	argv[0] = func_header;
	printf("\nType in input data...\n");
	while (fgets(input_buffer, LINE_BUFFER_SIZE, stdin)) {
		printf("Received raw input (without null):\n");
		putstr_raw(input_buffer, LINE_BUFFER_SIZE);
		
		cur = strtok(input_buffer, WHITESPACE);
		while (cur) {
			argv[argc++] = cur;
			cur = strtok(0, WHITESPACE);
		}

		printf("\nProgram's output:\n");
		callback(argc, argv);
		printf("\n%80c\nType in input data...\n", '-');
	}
}
