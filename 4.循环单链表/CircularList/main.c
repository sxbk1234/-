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

	printf("d3ʵ�ʲ��ǽ�β����\n");
	if (isbiaowei(L, d3))
		printf("���Ե�d3�ǽ�β����\n");
	else
		printf("���Ե�d3���ǽ�β����\n");



	printf("d4ʵ���ǽ�β����\n");
	if (isbiaowei(L, d4))
		printf("���Ե�d4�ǽ�β����\n");
	else
		printf("���Ե�d4���ǽ�β����\n");

	return 0;
}