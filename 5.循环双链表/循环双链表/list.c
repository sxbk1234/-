#include "list.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
	void* data;
	struct node* next;
	struct node* prior;
}node,*p_node;

struct node_head
{
	struct node* first;
	struct node* last;
	int node_number;
};



list createList(void)     //创建一个双向循环链表
{
	list L = (list)malloc(sizeof(struct node_head));
	L->first = NULL;
	L->last = NULL;
	L->node_number = 0;

	return L;
}

static p_node createNode(void* data)
{
	p_node p = (p_node)malloc(sizeof(node));
	p->data = data;
	return p;
}


void toucha(list L, void*data)//头插
{
	p_node p_n = createNode(data);
	if (L->node_number == 0)
	{

		L->first = p_n;
		L->last = p_n;
		L->node_number = 1;

		p_n->next = p_n;
		p_n->prior = p_n;
		return;
	}

	p_n->next = L->first;
	p_n->prior = L->last;

	L->first->prior = p_n;
	L->last->next = p_n;

	L->first = p_n;
	++(L->node_number);
}


void weicha(list L, void*data)//尾插
{
	p_node p_n = createNode(data);


	if (L->node_number == 0)
	{
		L->first = p_n;
		L->last = p_n;
		L->node_number = 1;

		p_n->next = p_n;
		p_n->prior = p_n;

		return;
	}

	p_n->next = L->first;
	p_n->prior = L->last;
	L->last->next = p_n;
	L->first->prior = p_n;
	L->last = p_n;

	++(L->node_number);
}



void print(void* data);

static void list_debug(list L)
{
	printf("L->node_number = %d\n", L->node_number);
	printf("L->first = %p\n", L->first);
	printf("L->last  = %p\n", L->last);
	printf("\n\n");
}

static void node_debug(p_node p_n)
{
	printf("p_n =       %p\n", p_n);
	printf("p_n->data = %p\n", p_n->data);
	printf("*(p_n->data) = ");
	print(p_n->data);
	printf("\n");
	printf("p_n->prior= %p\n", p_n->prior);
	printf("p_n->next = %p\n", p_n->next);

	printf("\n\n");
}

#ifdef PRINT_DATA
void print(void* data);
void print_data(list L)    //打印链表
{
	list_debug(L);
	p_node p_n = L->first;
	if (p_n == NULL)  return;


	while (p_n->next != L->first)
	{
		node_debug(p_n);
		p_n = p_n->next;
		getchar();
	}

	node_debug(p_n);
	putchar('\n');
	printf("-------------------------------------\n");
}

#endif


void weixucha(list L, void* data, weizhi qianorhou, int weixu) // 根据位序插入数据
{
	if (L->node_number == 0 || weixu < 1 || weixu > L->node_number) return;
	p_node p = createNode(data);

	p_node dingwei = L->first;

	--weixu;

	while (weixu)
	{
		dingwei = dingwei->next;
		--weixu;
	}

	if (qianorhou == qian)
	{
		p->next = dingwei;
		p->prior = dingwei->prior;

		p->next->prior = p;
		p->prior->next = p;

		if (dingwei == L->first)	L->first = p;
	}
	else
	{
		p->next = dingwei->next;
		p->prior = dingwei;

		p->prior->next = p;
		p->next->prior = p;

		if (dingwei == L->last)		L->last = p;
	}

	++(L->node_number);
}


int  data_number(list L)   //返回链表的数据数量
{
	return L->node_number;
}


#ifdef SHANCHU
void free_data(void*data);
void data_delete(list L, void* data)	//根据给出的数据删除节点
{
	p_node dingwei = L->first;

	while (1)
	{
		if (dingwei->data == data)
			break;
		else
			dingwei = dingwei->next;
	}

	dingwei->next->prior = dingwei->prior;
	dingwei->prior->next = dingwei->next;

	if (dingwei == L->first) L->first = dingwei->next;
	if (dingwei == L->last) L->last = dingwei->prior;

	--L->node_number;
}

void free_list(list L)					//释放链表
{
	p_node p_delete = L->first;
	if (p_delete == NULL) return;

	p_node p_next;

	while (p_delete->next != L->first)
	{
		p_next = p_delete->next;
		free_data(p_delete->data);
		free(p_delete);
		p_delete = p_next;
	}

	free_data(p_delete->data);
	free(p_delete);

	L->first = NULL;
	L->last = NULL;
	L->node_number = 0;
}

#endif


void* weixu_chazhao(list L, int weixu)  //根据位序返回数据
{
	if (weixu < 1 || weixu > L->node_number) return NULL;

	p_node dingwei = L->first;
	--weixu;
	while (weixu)
	{
		dingwei = dingwei->next;
		--weixu;
	}

	return dingwei->data;
}



void  genhuan_data(list L, void* data1, int weixu)    //更换位序处的数据
{
	if (weixu > L->node_number || weixu < 1) return;
	p_node p_n = L->first;

	--weixu;
	while (weixu)
	{
		--weixu;
		p_n = p_n->next;
	}

	free_data(p_n->data);
	p_n->data = data1;
}


