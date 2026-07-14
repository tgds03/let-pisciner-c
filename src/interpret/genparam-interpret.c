#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

const char *SPACE = " \f\n\r\t\v";
char strbuffer[81];
int random_range = 1 << 15;
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

int strtoint(const char *str) {
	char *endptr;
	int ret;

	errno = 0;
	ret = strtol(str, &endptr, 10);

	if (errno != 0) {
		trap("strtoint: errno(%d)", errno);
	} else if (*endptr != 0) {
		trap("strtoint: can not convert %s in %s", endptr, str);
	}

	return ret;
}

const char* strctok(const char *str, const char *delim, unsigned int *pidx) {
	static char buf[256];
	static const char *last = 0;

	const char *target = str;
	const char *res = buf;
	unsigned int idx = 0;

	if (target == 0) {
		target = last;
	}

	while (target[idx] != 0 && !strchr(delim, target[idx])) {
		buf[idx] = target[idx];
		++idx;
	}
	buf[idx] = 0;
	if (idx == 0) {
		res = 0;
	}

	while (target[idx] != 0 && strchr(delim, target[++idx]));
	last = target + idx;
	if (pidx != 0) {
		*pidx += idx;
	}
	return res;
}

void randomize_strbuffer() {
	int size = rand() % 81;
	int cur = 0;
	while (cur < size) {
		strbuffer[cur++] = 32 + rand() % 95;
	}
	strbuffer[cur] = 0;
}

void interpret(const char *const line) {
	unsigned int offset = 0;
	const char* token;
	int n;

	if ((token = strctok(line, SPACE, &offset)) == 0) {
		return;

	} else if (strcmp(token, "SET_INPUT") == 0) {
		while ((token = strctok(0, SPACE, 0))) {
			fprintf(inputfile, "%d ", strtoint(token));
		}
		fprintf(inputfile, "\n");

	} else if (strcmp(token, "RANDOMIZE_INPUT") == 0) {
		while ((token = strctok(0, SPACE, 0))) {
			if (strcmp(token, "int") == 0) {
				fprintf(inputfile, "%d ", rand() % random_range);
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
		n = strtoint(token);
		for (int i = 0; i < n; ++i) {
			interpret(line + offset);
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
		random_range = strtoint(randrangestr);
	}

	while (fgets(buffer, 256, stdin)) {
		printf("%4d: %s", ++count, buffer);
		interpret(buffer);
	}

	if (inputfile)
		fclose(inputfile);
	if (argfile)
		fclose(argfile);
	return 0;
}
