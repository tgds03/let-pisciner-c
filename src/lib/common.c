#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>
#include "common.h"

FunctionEnv function_env = {"", "", "", "", "", 0};

void init_rand(const char *str) {
	unsigned int seed = 0;
	int len = strlen(str);
	int offset = (len > 8) ? len - 8 : 0;
	seed = strtol(str + offset, 0, 16);
	srand(seed);
}

void randstr(char *str, unsigned int size, const char *charset) {
	const unsigned int numset = strlen(charset);
	while (size--) {
		*(str++) = charset[rand() % numset];
	}
	*str = 0;
}

#define LINE_BUFFER_SIZE 1024
#define MAX_ARGC 256
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

char *getshortpath(const char *orgpath) {
	char *dir, *base, *res;
	char *tempa, *tempb, *tempc;
	tempa = strdup(orgpath);
	tempb = strdup(orgpath);
	dir = dirname(tempa);
	base = basename(tempb);
	tempc = strdup(dir);
	dir = basename(tempc);
	res = (char*)calloc(strlen(dir) + strlen(base) + 2, sizeof(char));
	strcat(res, dir);
	strcat(res, "/");
	strcat(res, base);
	free(tempa);
	free(tempb);
	free(tempc);
	return res;
}

void init_test() {
	char *shortpath = 0;
	init_rand(function_env.stubmd5);
	signal(2, handle_signal); // interrupt
	signal(3, handle_signal); // quit
	signal(11, handle_signal); // segmentation fault
	signal(15, handle_signal); // terminated

	if (function_env.name[0] != 0) {
		snprintf(func_header,
				LINE_BUFFER_SIZE,
				"%s %s(%s);",
				function_env.type,
				function_env.name,
				function_env.param
		);
	} else {
		snprintf(func_header, LINE_BUFFER_SIZE, "undefined");
	}

	if (*function_env.path) {
		shortpath = getshortpath(function_env.path);
	}
	wprint("Let Pisciner C\n");
	wprint("File path: %s\n", (shortpath) ? shortpath : "");
	wprint("STUB MD5: %s\n", function_env.stubmd5);
	wprint("Target Function: %s\n", func_header);
	wprint("Press Ctrl + C to interrupt and exit.\n");
	putline('=');

	if (shortpath)
		free(shortpath);
}

void loop_test(void (*callback)(int, char*[])) {
	const char* WHITESPACE = " \x09\x0a\x0b\x0c\x0d";
	char *input_buffer;
	char *argv[MAX_ARGC], *pcur, *rcur, *wcur;
	char quote = 0;
	int input_buffer_size = LINE_BUFFER_SIZE;
	int argc = 1, idx, input_len;

	input_buffer = (char*)calloc(input_buffer_size, sizeof(char));
	argv[0] = func_header;
	wprint("Type in input data...\n");
	while (fgets(input_buffer, input_buffer_size, stdin)) {
		input_len = strlen(input_buffer);
		while (input_len >= input_buffer_size - 1) {
			input_buffer_size *= 2;
			input_buffer = (char*)realloc(input_buffer, input_buffer_size);
			fgets(input_buffer + input_len, input_buffer_size - input_len, stdin);
			input_len = strlen(input_buffer);
		}

		//tokenize
		argc = 1;
		wcur = input_buffer;
		pcur = " ";
		while (*wcur) {
			if (*wcur == '\\') {
				++wcur;
			} else if (*wcur == '\'' || *wcur == '"') {
				if (quote == 0) {
					quote = *wcur;
					argv[argc++] = wcur + 1;
				}
				else
					quote = 0;
				*wcur = 0;
			} else if (quote == 0) {
				if (strchr(WHITESPACE, *wcur)) {
					*wcur = 0;
				} else if (strchr(WHITESPACE, *pcur)) {
					argv[argc++] = wcur;
				}
			}
			pcur = wcur;
			++wcur;
		}

		if (quote != 0) {
			wprint("Parsing error.\n");
			continue;
		}
		wprint("Received input:\n");
		for (idx = 1; idx < argc; ++idx) {
			wprint("\"");
			wprint(argv[idx]);
			wprint("\"");
			if (idx < argc - 1)
				wprint(", ");
		}

		// escape
		for (idx = 1; idx < argc; ++idx) {
			wcur = argv[idx];
			rcur = argv[idx];
			while (*rcur) {
				if (*rcur == '\\') {
					++rcur;
					switch (*rcur) {
						case '0': *wcur = '\0'; break;
						case 'a': *wcur = '\a'; break;
						case 'b': *wcur = '\b'; break;
						case 't': *wcur = '\t'; break;
						case 'n': *wcur = '\n'; break;
						case 'v': *wcur = '\v'; break;
						case 'f': *wcur = '\f'; break;
						case 'r': *wcur = '\r'; break;
						case '\\': *wcur = '\\'; break;
						case '\'': *wcur = '\''; break;
						case '"': *wcur = '"'; break;
						case 0: *wcur = '\\'; break;
						default: *wcur = *rcur; break;
					}
					if (*rcur == 0) {
						++wcur;
						break;
					}
				} else {
					*wcur = *rcur;
				}
				pcur = rcur;
				++wcur;
				++rcur;
			}
			*wcur = 0;
		}

		wprint("\nProgram's output:\n");
		callback(argc, argv);
		wprint("\n\nType in input data...\n");
	}
	wprint("File closed.\n");
	free(input_buffer);
}
