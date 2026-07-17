// reference: https://todaycode.tistory.com/73
#include <stdlib.h>
#include <assert.h>
#include "basic-ds.h"

extern const char *SPACE;

int	get_priority(char c) {
	if (c == '*') return 2;
	else if (c == '/') return 2;
	else if (c == '%') return 2;
	else if (c == '+') return 1;
	else if (c == '-') return 1;
	else return 0;
}

int arithm_parse(char *str) {
	stack_arithm *s = create();
	stack_artihm *b = create();
	tokenize(s, str);
}

void tokenize(stack_arithm *s, char *str) {
	arithm_elem elem;
	char *endptr;
	int num;
	str = strtok(str, SPACE);
	while (*str) {
		if ('0' <= *str && *str <= '9') {
			num = strtol(str, &endptr, SPACE);
			elem.oper = 0;
			elem.num = num;
			push(s, elem);
		} else if (*str == '+' || *str == '-') {
			if (get_priority(peek(s).oper) > 0) {
				num = strtol(str, &endptr, SPACE);
				elem.oper = 0;
				elem.num = num;
				push(s, elem);
			} else {
				elem.oper = *str;
				elem.num = num;
				push(s, elem);
				endptr = str + (*str != 0);
			}
		} else {
			elem.oper = *str;
			elem.num = num;
			push(s, elem);
			endptr = str + (*str != 0);
		}
		str = endptr;
		if ((9 <= *str && *str <= 13) || *str == ' ') {
			str = strtok(str, SPACE);
		}
	}
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
				while (!peek(buffer).oper != '(') {
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
}


/*
int arithm_parse(char *str) {
	stack_char *buffer = create();
	stack_char *postfix = create();
	int p;

	// from midfix to postfix
	while (*str) {
		if (_is_space(*str)) {
			++str;
			continue;
		} else if ('0' <= *str && *str <= '9') {
			push(postfix, *str);
		} else if (*str == '(') {
			push(postfix, *str);
		} else if (*str == ')') {
			while (peek(buffer) != '(') {
				push(postfix, pop(buffer));
			}
			pop(buffer);
		} else {
			p = _get_priority(*str);
			assert(p);

			if (isempty(buffer)) {
				push(buffer, *str);
			} else if (peek(buffer) == '(') {
				push(buffer, *str);
			} else if (p > _get_priority(peek(buffer))) {
				push(buffer, *str);
			} else {
				while (!isempty(buffer) || p <= _get_priority(peek(buffer))) {
					push(postfix, pop(buffer));
				}
			}
		}
		++str;
	}

	while (!isempty(buffer)) {
		push(postfix, pop(buffer));
	}

	// interpret postfix arithmath
	char cur;
	int idx = 0;
	int a, b;
	while (idx <= postfix->topidx) {
		cur = postfix->data[idx];
		if ('0' <= cur && cur <= '9') {
			push(buffer, cur);
		} else {
			b = pop(buffer) - '0';
			a = pop(buffer) - '0';
			if (cur == '+') {
				push(buffer, '0' + (a + b));
			} else if (cur == '-') {
				push(buffer, '0' + (a - b));
			}
		}
		++idx;
	}

}

int _is_space(char c) {
	if (9 <= c && c <= 13) return 1;
	else if (c == ' ') return 1;
	else return 0;
}

*/
