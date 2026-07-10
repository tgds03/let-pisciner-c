#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>
#include "common.h"

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

void wprint(const char *str, ...) {
	static int _wprint_capacity = 0;
	static char *_wprint_buffer = 0;

	int reqlen = 0;
	va_list argptr;

	va_start(argptr, str);
	reqlen = vsnprintf(0, 0, str, argptr);
	va_end(argptr);

	if (_wprint_capacity < reqlen + 1) {
		free(_wprint_buffer);
		_wprint_capacity *= 2;
		if (_wprint_capacity == 0)
			_wprint_capacity = LINE_BUFFER_SIZE;
		_wprint_buffer = (char*)malloc(sizeof(char) * _wprint_capacity);
	}

	va_start(argptr, str);
	vsnprintf(_wprint_buffer, reqlen + 1, str, argptr);
	va_end(argptr);

	fflush(stdout);
	write(1, _wprint_buffer, reqlen);
}

void handle_signal(int sig) {
	wprint("\nReceived signal %d", sig);
	wprint("\nexit\n");
	exit(0);
}

void putline(char c) {
	char line[81];
	for (int i = 0; i < 80; ++i) {
		line[i] = c;
	}
	line[80] = 0;
	wprint("%s\n", line);
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
	wprint("Let Pisciner C\n");
	wprint("Compiled: %s\n", function_env.path);
	wprint("Function: %s\n", func_header);
	wprint("Press Ctrl + C to interrupt and exit.\n");
	putline('=');
}

void loop_test(void (*callback)(int, char*[])) {
	const char* WHITESPACE = " \x09\x0a\x0b\x0c\x0d";
	char input_buffer[LINE_BUFFER_SIZE];
	char *argv[LINE_BUFFER_SIZE], *cur;
	int argc = 1;

	argv[0] = func_header;
	wprint("Type in input data...\n");
	while (fgets(input_buffer, LINE_BUFFER_SIZE, stdin)) {
		wprint("Received input:\n");
		wprint(input_buffer);
		
		argc = 1;
		cur = strtok(input_buffer, WHITESPACE);
		while (cur) {
			argv[argc++] = cur;
			cur = strtok(0, WHITESPACE);
		}

		wprint("\nProgram's output:\n");
		callback(argc, argv);
		wprint("\n\nType in input data...\n");
	}
	wprint("File closed.\n");
}
