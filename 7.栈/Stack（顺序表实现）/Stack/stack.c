#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


struct stack_head
{
	void** data;
	int stack_size;
	void** stack_top;
};

stack createStack(int stacksize)		//����һ��ջ
{
	stack st = (stack)malloc(sizeof(struct stack_head));
	st->data = (void**)malloc(sizeof(void*) * stacksize);
	st->stack_size = stacksize;
	st->stack_top = st->data - 1;

	return st;
}


bool  ruzhan(stack st, void* data)  //��ջ
{
	if (st->data + st->stack_size - 1 == st->stack_top)
		return false;

	++st->stack_top;
	*(st->stack_top) = data;
	return true;
}


#ifdef PRINT_STACK
void  print_data(void* data);
void  print_stack(stack st)		//��ӡջ
{
	if (st->data > st->stack_top) return;

	void**data = st->data;

	while (data != st->stack_top)
	{
		print_data(*data);
		++data;
	}

	print_data(*data);

	putchar('\n');
}

#endif