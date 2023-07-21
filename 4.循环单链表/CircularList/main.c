#include <stdio.h>
#include "xunhuanList.h"
#include <stdlib.h>

void print(void* data)
{
	int* p = (int*)data;

	printf("%d	", *p);
}

int main(void)
{
	xunhuanlist L = createList();

	int* d1 = (int*)malloc(sizeof(int));
	int* d2 = (int*)malloc(sizeof(int));
	int* d3 = (int*)malloc(sizeof(int));
	int* d4 = (int*)malloc(sizeof(int));

	*d1 = 1;
	*d2 = 2;
	*d3 = 3;
	*d4 = 4;

	toucha(L, d2);
	toucha(L, d1);
	weicha(L, d3);
	weicha(L, d4);
	print_data(L);

	printf("d3实际不是结尾数据\n");
	if (isbiaowei(L, d3))
		printf("测试得d3是结尾数据\n");
	else
		printf("测试得d3不是结尾数据\n");



	printf("d4实际是结尾数据\n");
	if (isbiaowei(L, d4))
		printf("测试得d4是结尾数据\n");
	else
		printf("测试得d4不是结尾数据\n");

	return 0;
}