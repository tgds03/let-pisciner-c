#include <stdlib.h>
#include <assert.h>
#include "basic-ds.h"

#define DEFAULT_CAPACITY 256

stack_char *create() {
	stack_char *stack = (stack_char *)malloc(sizeof(stack_char));
	stack->topidx = -1;
	stack->capacity = DEFAULT_CAPACITY;
	stack->data = (char *)malloc(sizeof(char) * DEFAULT_CAPACITY);
	return stack;
}

void push(stack_char *stack, char data) {
	assert(stack && "Stack is null");
	if (stack->topidx <= stack->capacity - 1) {
		while (stack->topidx <= stack->capacity - 1)
			stack->capacity *= 2;
		stack->data = (char *)realloc(sizeof(char) * stack->capacity);
	}
	stack->data[++stack->topidx] = data;
}

char pop(stack_char stack) {
	assert(stack && "Stack is null");
	assert(stack->topidx >= 0 && "Tried pop empty stack");
	return stack->data[stack->topidx--];
}

void destroy(stack_char *stack) {
	assert(stack && "Stack is null");
	free(stack->data);
	free(stack);
}

int isempty(stack_char *stack) {
	assert(stack && "Stack is null");
	return (stack->topidx == -1);
}

char peek(stack_char *stack) {
	assert(stack && "Stack is null");
	assert(stack->topidx >= 0 && "Tried pop empty stack");
	return stack->data[stack->topidx];
}
