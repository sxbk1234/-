#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"
void  print(void* data)
{
	int* p = (int*)data;

	printf("%d	", *p);
}

bool xiangdeng(void* a, void* b)
{
	int* c = (int*)a;
	int* d = (int*)b;

	if (*c == *d)
		return true;
	else
		return false;
}


int main(void)
{
	int* data[15];

	for (int i = 0; i < 15; ++i)
		data[i] = (int*)malloc(sizeof(int));
	

	for (int i = 0; i < 15; ++i)
		*(data[i]) = i;


	SeqList* L = CreateList(5);

	for (int i = 0; i < 15; ++i)
	{
		shunxu_insert(L, data[i]);
	}

	int* data2 = (int*)malloc(sizeof(int));
	int* data3 = (int*)malloc(sizeof(int));

	int* data4 = (int*)malloc(sizeof(int));
	int* data5 = (int*)malloc(sizeof(int));

	*data2 = 20;
	*data3 = 21;

	*data4 = 22;
	*data5 = 23;

	ListInsert(L, data2, 1, qian);
	ListInsert(L, data3, 2, hou);

	ListInsert(L, data4, data_number(L), qian);
	ListInsert(L, data5, data_number(L), hou);

	print_list(L);

	int* data6;
	ListDelete(L, &((void*)data6), 1);
	printf("被删除的数字为%d\n", *data6);

	print_list(L);


	int*p = (int*)GetElem(L, 5);
	printf("返回的值为%d\n", *p);
	print_list(L);

	
	int* p1 = (int*)malloc(sizeof(int));
	*p1 = 23;
	int cixu = LocateElem(L, p1);
	printf("*p1的值为%d，次序为%d\n", *p1, cixu);
	print_list(L);

	int* p2 = (int*)malloc(sizeof(int));
	*p2 =100;
	int cixu2 = LocateElem(L, p2);
	printf("*p2的值为%d，次序为%d\n", *p2, cixu2);
	print_list(L);

	return 0;
}