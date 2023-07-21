#include <stdio.h>
#include "LinkList.h"
#include <stdlib.h>

void print(void* data)
{
	int* p = (int*)data;
	printf("%d	", *p);
}

bool free_data(void* data)
{
	free(data);

	return true;
}

bool xiangdeng(void* data1, void* data2)
{
	int* p1 = (int*)data1;
	int* p2 = (int*)data2;

	return   *p1 == *p2 ? true : false;
}

int main(void)
{
	LinkList L = createLinkList();

	int* p_data3 = (int*)malloc(sizeof(int));
	int* p_data4 = (int*)malloc(sizeof(int));
	int* p_data5 = (int*)malloc(sizeof(int));
	int* p_data6 = (int*)malloc(sizeof(int));

	*p_data3 = 11;
	*p_data4 = 12;
	*p_data5 = 13;
	*p_data6 = 14;

	weixucha(L, p_data3, 1, qian);
	weixucha(L, p_data4, 1, hou);
	weixucha(L, p_data5, List_lenght(L), qian);
	weixucha(L, p_data6, List_lenght(L), hou);

	print_list(L);
	nizhi(L);
	print_list(L);

	return 0;
}