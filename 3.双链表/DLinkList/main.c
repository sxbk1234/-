#include <stdio.h>
#include "DLinkList.h"
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
	DLinkList  L = createDLinkList();

	int* data1 = (int*)malloc(sizeof(int));
	int* data2 = (int*)malloc(sizeof(int));
	int* data3 = (int*)malloc(sizeof(int));
	int* data4 = (int*)malloc(sizeof(int));

	*data1 = 1;
	*data2 = 2;
	*data3 = 3;
	*data4 = 4;

	houcha(L, data1);
	houcha(L, data2);
	houcha(L, data3);
	houcha(L, data4);
	print_data(L);

	free_list(L);
	print_data(L);

	free_list(L);
	print_data(L);

	return 0;
}