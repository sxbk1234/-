#include "SLinkList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	void* data;
	int   next;
}node;


static int list_max_size;
static int list_yiyong;


void print(slinklist L)					//打印链表
{
	for (int i = 0; i < list_max_size + 2; ++i)
	{
		printf("%d	", (L + i)->next);
	}

	putchar('\n');
}

slinklist createList(int listsize)			//创建静态链表
{
	list_max_size = listsize;
	list_yiyong = 0;
	slinklist list = (slinklist)malloc(sizeof(node) * (listsize + 2));

	(list + 0)->next = 0;
	(list + listsize+2 - 1)->next = 1;
	(list + listsize+2 - 2)->next = 0;

	for (int i = 0; i < listsize-1; ++i)
	{
		(list + i + 1)->next = i + 2;
	}
	printf("初始化时打印\n");
	print(list);
	return list;
}



void  charu(slinklist L, void* data)			//插入
{
	if (list_max_size == list_yiyong) return;
	++list_yiyong;

	int xunzhao = 0;
	while ((L + xunzhao)->next != 0)
		xunzhao = (L + xunzhao)->next;

	(L + xunzhao)->next = (L + list_max_size + 2 - 1)->next;
	(L + list_max_size + 2 - 1)->next = (L + (L + list_max_size + 2 - 1)->next)->next;
	(L + ((L + xunzhao)->next))->next = 0;
	(L + ((L + xunzhao)->next))->data = data;

}


void  shanchu(slinklist L,int weixu)					//根据位序删除
{
	if (weixu < 1 || weixu>list_yiyong) return;

	int dingwei = 0;
	--weixu;
	while (weixu)
	{
		dingwei = (L + dingwei)->next;
		--weixu;
	}


	int k = (L + dingwei)->next;
	int i = (L + ((L + dingwei)->next))->next;
	int j = (L + list_max_size + 2 - 1)->next;

	(L + dingwei)->next = i;
	(L + list_max_size + 2 - 1)->next = k;
	(L + k)->next = j;


}