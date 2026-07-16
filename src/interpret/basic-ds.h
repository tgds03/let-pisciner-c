#ifndef BASIC_DS_H
#define BASIC_DS_H

typedef struct {
	char *data;
	int topidx;
	int capacity;
} stack_char;

stack_char *create();
void push(stack_char *stack, char data);
char pop(stack_char *stack);
void destroy(stack_char *stack);
int isempty(stack_char *stack);
char peek(stack_char *stack);

#endif
