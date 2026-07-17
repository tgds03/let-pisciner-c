#include <stdlib.h>
#include <assert.h>
#include "basic-ds.h"

#define DEFAULT_CAPACITY 256

stack_arithm *create() {
	stack_arithm *stack = (stack_arithm *)malloc(sizeof(stack_arithm));
	stack->topidx = -1;
	stack->capacity = DEFAULT_CAPACITY;
	stack->data = (arithm_elem *)malloc(sizeof(arithm_elem) * DEFAULT_CAPACITY);
	return stack;
}

void push(stack_arithm *stack, arithm_elem data) {
	assert(stack && "Stack is null");
	if (stack->topidx <= stack->capacity - 1) {
		while (stack->topidx <= stack->capacity - 1)
			stack->capacity *= 2;
		stack->data = (arithm_elem *)realloc(stack->data, sizeof(arithm_elem) * stack->capacity);
	}
	stack->data[++stack->topidx].oper = data.oper;
	stack->data[stack->topidx].num = data.num;
}

arithm_elem pop(stack_arithm *stack) {
	assert(stack && "Stack is null");
	assert(stack->topidx >= 0 && "Tried pop empty stack");
	return stack->data[stack->topidx--];
}

void destroy(stack_arithm *stack) {
	assert(stack && "Stack is null");
	free(stack->data);
	free(stack);
}

int isempty(stack_arithm *stack) {
	assert(stack && "Stack is null");
	return (stack->topidx == -1);
}

arithm_elem peek(stack_arithm *stack) {
	assert(stack && "Stack is null");
	assert(stack->topidx >= 0 && "Tried pop empty stack");
	return stack->data[stack->topidx];
}

arithm_elem get(stack_arithm *stack, int idx) {
	assert(stack && "Stack is null");
	assert(0 <= idx && idx <= stack->topidx && "Tried access out of range");
	return stack->data[idx];
}
