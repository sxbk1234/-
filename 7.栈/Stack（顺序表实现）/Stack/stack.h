#ifndef STACK
#define STACK
#include <stdbool.h>

#define PRINT_STACK

typedef struct stack_head* stack;

stack createStack(int stacksize);    //创建一个栈
bool  ruzhan(stack st, void* data);  //入栈

void  print_stack(stack st);		//打印栈
									//需要定义函数void print_data(void*data);
									//需要定义宏PRINT_STACK
#endif