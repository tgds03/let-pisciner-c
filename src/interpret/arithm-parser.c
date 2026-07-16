// reference: https://todaycode.tistory.com/73
#include <stdlib.h>
#include <assert.h>
#include "basic-ds.h"

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

int	_get_priority(char c) {
	if (c == '*') return 2;
	else if (c == '/') return 2;
	else if (c == '%') return 2;
	else if (c == '+') return 1;
	else if (c == '-') return 1;
	else return 0;
}

int _is_space(char c) {
	if (9 <= c && c <= 13) return 1;
	else if (c == ' ') return 1;
	else return 0;
}
