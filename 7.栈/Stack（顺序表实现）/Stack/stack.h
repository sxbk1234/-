#ifndef STACK
#define STACK
#include <stdbool.h>

#define PRINT_STACK

typedef struct stack_head* stack;

stack createStack(int stacksize);    //����һ��ջ
bool  ruzhan(stack st, void* data);  //��ջ

void  print_stack(stack st);		//��ӡջ
									//��Ҫ���庯��void print_data(void*data);
									//��Ҫ�����PRINT_STACK
#endif