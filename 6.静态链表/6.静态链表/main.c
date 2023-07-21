#include "SLinkList.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	slinklist  L = createList(10);

	int* d1 = (int*)malloc(sizeof(int));
	int* d2 = (int*)malloc(sizeof(int));
	int* d3 = (int*)malloc(sizeof(int));
	int* d4 = (int*)malloc(sizeof(int));
	int* d5 = (int*)malloc(sizeof(int));
	int* d6 = (int*)malloc(sizeof(int));
	int* d7 = (int*)malloc(sizeof(int));
	int* d8 = (int*)malloc(sizeof(int));
	int* d9 = (int*)malloc(sizeof(int));
	int* d10= (int*)malloc(sizeof(int));
	int* d11= (int*)malloc(sizeof(int));

	*d1 = 11;
	*d2 = 22;
	*d3 = 33;
	*d4 = 44;
	*d5 = 55;
	*d5 = 66;
	*d5 = 77;
	*d5 = 88;
	*d5 = 99;
	*d5 = 100;
	*d5 = 110;

	charu(L, d1);
	charu(L, d2);
	charu(L, d3);
	charu(L, d4);
	charu(L, d5);
	charu(L, d6);
	charu(L, d7);
	charu(L, d8);
	charu(L, d9);
	charu(L, d10);
	charu(L, d11);

	print(L);

	shanchu(L, 2);
	shanchu(L, 3);
	shanchu(L, 5);

	print(L);


	return 0;
}