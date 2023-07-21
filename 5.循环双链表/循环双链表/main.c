#include <stdio.h>
#include "list.h"
#include <stdlib.h>

void print(void* data)
{
	int* p = (int*)data;
	printf("%d	", *p);
}

void free_data(void* data)
{
	free(data);
}

int main(void)
{
	list L = createList();

	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	int* p3 = (int*)malloc(sizeof(int));
	int* p4 = (int*)malloc(sizeof(int));

	*p1 = 1;
	*p2 = 2;
	*p3 = 3;
	*p4 = 4;

	toucha(L, p2);
	toucha(L, p1);
	weicha(L, p3);
	weicha(L, p4);


	print_data(L);
	int* p5 = (int*)malloc(sizeof(int));
	*p5 = 5;
	genhuan_data(L,p5,1);
	print_data(L);

	free_list(L);

	print_data(L);
	return 0;
}