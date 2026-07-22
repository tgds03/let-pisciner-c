#ifndef BASIC_DS_H
#define BASIC_DS_H

typedef struct {
	char oper;	// 0: num elem, else: oper elem
	int num;
} arithm_elem;

typedef struct {
	arithm_elem *data;
	int topidx;
	int capacity;
} stack_arithm;

stack_arithm *create();
void push(stack_arithm *stack, arithm_elem data);
arithm_elem pop(stack_arithm *stack);
void destroy(stack_arithm *stack);
int isempty(stack_arithm *stack);
arithm_elem peek(stack_arithm *stack);
arithm_elem get(stack_arithm *stack, int idx);

#endif
