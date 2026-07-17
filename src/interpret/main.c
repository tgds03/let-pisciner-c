#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include "arithm-parser.h"

const char *SPACE = " \f\n\r\t\v";
char strbuffer[81];
int random_range = 1 << 16;
FILE *inputfile = 0;
FILE *argfile = 0;

void trap(const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	if (inputfile)
		fclose(inputfile);
	if (argfile)
		fclose(argfile);
	exit(EXIT_FAILURE);
}

int strtoint(const char *str, const char** endptr) {
	char *end;
	int ret;

	errno = 0;
	ret = strtol(str, &end, 10);

	if (errno != 0) {
		trap("strtoint: errno(%d)", errno);
	}
	if (endptr) {
		*endptr = end;
	}

	return ret;
}

const char* strctok(const char *str, const char *delim, unsigned int *nextoffset) {
	static char buf[256];
	static const char *last = 0;
	static unsigned int offset = 0;

	int idx = 0;

	if (str != 0) {
		offset = 0;
		last = str;
	}

	while (last[offset] != 0 && !strchr(delim, last[offset])) {
		buf[idx++] = last[offset++];
	}
	buf[idx] = 0;
	if (nextoffset != 0) {
		*nextoffset = offset;
	}

	while (last[offset] != 0 && strchr(delim, last[offset]))
		++offset;

	return buf;
}

void randomize_strbuffer() {
	int size = rand() % 16 + 1;
	int cur = 0;
	while (cur < size) {
		strbuffer[cur++] = 33 + rand() % 94;
	}
	strbuffer[cur] = 0;
}

char getrand_char() {
	return rand() % 128;
}

char getrand_pchar() {
	return 32 + rand() % 95;
}

int getrand_int() {
	return (rand() % random_range) - random_range / 2;
}

int getrand_uint() {
	return (rand() % random_range);
}

void interpret(const char *const line, int iter) {
	const char *token;
	unsigned int offset;
	int n;

	if ((token = strctok(line, SPACE, 0)) == 0) {
		return;

	} else if (strcmp(token, "SET_INPUT") == 0) {
		while ((token = strctok(0, SPACE, &offset))) {
			if (strncmp(token, "$(", 2) == 0) {
				token = strctok(line + offset, ")", 0);
				parse_env.iter = iter;
				arithm_parse(token);			
			} else {
				fprintf(inputfile, "%s ", token);
			}
		}
		fprintf(inputfile, "\n");

	} else if (strcmp(token, "RANDOMIZE_INPUT") == 0) {
		while ((token = strctok(0, SPACE, 0))) {
			if (strcmp(token, "int") == 0) {
				fprintf(inputfile, "%d ", getrand_int());
			} else if (strcmp(token, "uint") == 0) {
				fprintf(inputfile, "%d ", getrand_uint());
			} else if (strcmp(token, "char") == 0) {
				fprintf(inputfile, "%c ", getrand_char());
			} else if (strcmp(token, "pchar") == 0) {
				fprintf(inputfile, "%c ", getrand_pchar());
			} else if (strcmp(token, "str") == 0) {
				randomize_strbuffer();
				fprintf(inputfile, "%s ", strbuffer);
			} else {
				trap("can not interpret type %s", token);
			}
		}
		fprintf(inputfile, "\n");
	} else if (strcmp(token, "REPEAT") == 0) {
		token = strctok(0, SPACE, &offset);
		n = strtoint(token, 0);
		for (int i = 0; i < n; ++i) {
			interpret(line + offset, i);
		}
	} else {
		trap("can not interpret command: %s", token);
	}
}

int main(int argc, char *argv[]) {
	char buffer[256];
	char *randseedstr, *randrangestr;
	int randseed = 0, randiter;
	int count = 0;

	if (argc == 3) {
		errno = 0;
		inputfile = fopen(argv[1], "w");
		if (!inputfile) {
			trap("can not open inputfile %s (errno: %d", argv[1], errno);
		}

		errno = 0;
		argfile = fopen(argv[2], "w");
		if (!argfile) {
			trap("can not open argfile %s (errno: %d", argv[2], errno);
		}

	} else {
		trap("usage: %s [inputfile] [argfile]", argv[0]);
	}

	if ((randseedstr = getenv("RANDSEED"))) {
		while (*randseedstr) {
			randseed += (int)*randseedstr;
			++randseedstr;
		}
		randiter = randseed % 512;
		for (int i = 0; i < randiter; ++i) {
			rand();
		}
		randseed = rand();
		printf("random seed from enviorment: %d\n", randseed);
		srand(randseed);
	}

	if ((randrangestr = getenv("RANDRANGE"))) {
		random_range = strtoint(randrangestr, 0);
	}

	while (fgets(buffer, 256, stdin)) {
		printf("%4d: %s", ++count, buffer);
		interpret(buffer, 0);
	}

	if (inputfile)
		fclose(inputfile);
	if (argfile)
		fclose(argfile);
	return 0;
}
