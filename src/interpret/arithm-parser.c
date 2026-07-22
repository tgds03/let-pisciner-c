// reference: https://todaycode.tistory.com/73
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "arithm-parser.h"
#include "basic-ds.h"

extern const char *SPACE;
struct ParseEnv parse_env;

int	get_priority(char c) {
	if (c == '*') return 2;
	else if (c == '/') return 2;
	else if (c == '%') return 2;
	else if (c == '+') return 1;
	else if (c == '-') return 1;
	else return 0;
}

void tokenize(stack_arithm *s, const char *str);
void postfix(stack_arithm *dest, stack_arithm *src);
int arithmath(stack_arithm *s);

#include <stdio.h>
int arithm_parse(const char *str) {
	stack_arithm *s = create();
	stack_arithm *b = create();
	int res;

	tokenize(s, str);
	printf("tokenize\n");
	postfix(b, s);
	printf("postfix\n");
	res = arithmath(b);
	printf("arithmath\n");
	destroy(s);
	destroy(b);
	return res;
}

void tokenize(stack_arithm *s, const char *str) {
	arithm_elem elem;
	char *cpystr, *nextptr, *cur;
	int num;

	cpystr = strdup(str);
	cur = strtok(cpystr, SPACE);
	while (cur) {
		if (*cur == '\\') {
			if (cur[1] == 'i') {
				elem.oper = 0;
				elem.num = parse_env.iter;
				push(s, elem);
			}
			nextptr = cur + 2;
		} else if ('0' <= *cur && *cur <= '9') {
			num = strtol(cur, &nextptr, 10);
			elem.oper = 0;
			elem.num = num;
			push(s, elem);
		} else if (*cur == '+' || *cur == '-') {
			if (get_priority(peek(s).oper) > 0) {
				num = strtol(cur, &nextptr, 10);
				elem.oper = 0;
				elem.num = num;
				push(s, elem);
			} else {
				elem.oper = *cur;
				elem.num = 0;
				push(s, elem);
				nextptr = cur + (*cur != 0);
			}
		} else {
			elem.oper = *cur;
			elem.num = 0;
			push(s, elem);
			nextptr = cur + (*cur != 0);
		}
		if (*nextptr == 0) {
			cur = strtok(0, SPACE);
		} else {
			cur = nextptr;
		}
		// if ((9 <= *cur && *cur <= 13) || *cur == ' ') {
		// 	cur = strtok(0, SPACE);
		// }
	}
	free(cpystr);
}

void postfix(stack_arithm *dest, stack_arithm *src) {
	stack_arithm *buffer = create();
	int i;

	for (i = 0; i <= src->topidx; ++i) {
		if (src->data[i].oper == 0) {
			push(dest, src->data[i]);
		} else {
			if (isempty(buffer)) {
				push(buffer, src->data[i]);
			} else if (src->data[i].oper == '(') {
				push(buffer, src->data[i]);
			} else if (src->data[i].oper == ')') {
				while (peek(buffer).oper != '(') {
					push(dest, pop(buffer));
				}
				pop(buffer);
			} else if (get_priority(src->data[i].oper) > get_priority(peek(buffer).oper)) {
				push(buffer, src->data[i]);
			} else {
				while (!isempty(buffer) || get_priority(src->data[i].oper) <= get_priority(peek(buffer).oper)) {
					push(dest, pop(buffer));
				}
				push(buffer, src->data[i]);
			}
		}
	}

	while (!isempty(buffer)) {
		push(dest, pop(buffer));
	}
	destroy(buffer);
}


int arithmath(stack_arithm *s) {
	arithm_elem elem;
	stack_arithm *buffer = create();
	int i;
	int a, b;

	elem.oper = 0;
	for (i = 0; i <= s->topidx; ++i) {
		if (s->data[i].oper == 0) {
			elem.num = s->data[i].num;
			push(buffer, elem);
		} else {
			b = pop(buffer).num;
			a = pop(buffer).num;
			switch (s->data[i].oper) {
				case '+':
					elem.num = a + b;
					break;
				case '-':
					elem.num = a - b;
					break;
				case '*':
					elem.num = a * b;
					break;
				case '/':
					elem.num = a / b;
					break;
				case '%':
					elem.num = a / b;
					break;
				default:
					assert(0 && "Invalid operation");
			}
			push(buffer, elem);
		}
	}
	elem = pop(buffer);
	if (!isempty(buffer))
		assert(0 && "Invalid expression");
	destroy(buffer);
	return elem.num;
}
