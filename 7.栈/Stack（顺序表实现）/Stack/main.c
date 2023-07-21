#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


void print_data(void* data)
{
	int* p = (int*)data;

	printf("%d	", *p);
}

int main(void)
{
	stack st = createStack(5);

	int* d1 = malloc(sizeof(int));
	int* d2 = malloc(sizeof(int));
	int* d3 = malloc(sizeof(int));
	int* d4 = malloc(sizeof(int));
	int* d5 = malloc(sizeof(int));
	int* d6 = malloc(sizeof(int));

	*d1 = 1;
	*d2 = 2;
	*d3 = 3;
	*d4 = 4;
	*d5 = 5;
	*d6 = 6;

	ruzhan(st, d1);
	ruzhan(st, d2);
	ruzhan(st, d3);
	ruzhan(st, d4);
	ruzhan(st, d5);
	ruzhan(st, d6);

	print_stack(st);

	return 0;
}