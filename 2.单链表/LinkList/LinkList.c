#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>
struct LNode
{
	void* data;
	struct LNode* next;
};


LinkList createLinkList(void)		//创建一个空链表
{
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->data = NULL;
	L->next = NULL;

	return L;
}

bool  IsEmpty(LinkList L)            //判断链表是否为空
{
	if (L->next == NULL)	return true;
	else					return false;
}


static LNode* createNode(void* data)
{
	LNode* node_p = (LNode*)malloc(sizeof(LNode));
	node_p->data = data;
	node_p->next = NULL;

	return node_p;
}
void  toucha(LinkList L, void* data)			//头插
{
	LNode* node_p = createNode(data);
	node_p->next = L->next;
	L->next = node_p;
}

void  weicha(LinkList L, void* data)			//尾插
{
	LNode* node_p = createNode(data);
	LNode* qian = L;
	LNode* hou = L->next;

	while (hou != NULL)
	{
		hou = hou->next;
		qian = qian->next;
	}

	qian->next = node_p;
}



#ifdef PRINT_LIST
void print(void*);
void print_list(LinkList L)		//打印链表
{
	LNode* bianli = L->next;
	while (bianli != NULL)
	{
		print(bianli->data);
		bianli = bianli->next;
	}
	putchar('\n');
}

#endif



bool  weixucha(LinkList L, void* data, int weixu, weizhi qian_or_hou)	//位序插
{
	LNode* dingwei = L;
	if (qian_or_hou == qian)
		--weixu;
	
	while (weixu > 0 && dingwei != NULL)
	{
		--weixu;
		dingwei = dingwei->next;
	}

	if (dingwei == NULL) return false;

	LNode* node_p = createNode(data);
	node_p->next = dingwei->next;
	dingwei->next = node_p;

	return true;
}


int   List_lenght(LinkList L)      //链表长度
{
	LNode* p = L->next;
	int ret = 0;

	while (p != NULL)
	{
		++ret;
		p = p->next;
	}

	return ret;
}




#ifdef SHANCHU

bool free_data(void* data);

bool weishan(LinkList L)			//尾删
{
	LNode* qian = L->next;
	if (qian == NULL) return true;

	LNode* hou = qian->next;
	LNode* qian_qian = L;
	while (hou != NULL)
	{
		qian_qian = qian_qian->next;
		qian = qian->next;
		hou = hou->next;
	}

	if (free_data(qian->data))
	{
		free(qian);
		qian_qian->next = NULL;

		return true;
	}

	return false;
}

bool toushan(LinkList L)            //头删
{
	LNode* p_delete = L->next;

	if (p_delete == NULL) return true;
	
	if (free_data(p_delete->data))
	{
		L->next = p_delete->next;
		free(p_delete);

		return true;
	}

	return false;
}

bool weixushan(LinkList L, int weixu)	//位序删
{
	if (weixu<1 || weixu>List_lenght(L))
		return false;

	LNode* qian = L;
	--weixu;
	while (weixu)
	{
		qian = qian->next;
		--weixu;
	}

	if (free_data(qian->next->data))
	{
		LNode* p_delete = qian->next;
		qian->next = qian->next->next;
		free(p_delete);
	}
	return false;
}

bool xiangdeng(void* data1, void* data2);
void yuansu_shan(LinkList L, void** data) //元素删
{
	LNode* p_qian = L;
	LNode* p_delete = L->next;

	while (p_delete != NULL)
	{
		if (*data == p_delete->data)
		{
			p_qian->next = p_delete->next;
			free_data(*data);
			free(p_delete);
			*data = NULL;
			return;
		}
		p_qian = p_qian->next;
		p_delete = p_delete->next;
	}
}

#endif



void* weixuchazhao(LinkList L, int i)			//按位序查找
{
	LNode* p_ret = L;
	while (i > 0 && p_ret != NULL)
	{
		p_ret = p_ret->next;
		--i;
	}

	if (p_ret != NULL)
		return p_ret->data;
	else
		return NULL;
}



#ifdef ANZHICHAZHAO
bool xiangdeng(void* data1, void* data2);
int   anzhichazhao(LinkList L, void* data) //按值查找
{
	LNode* p_chazhao = L->next;
	int ret = 0;
	while (p_chazhao != NULL)
	{
		if (xiangdeng(p_chazhao->data, data))
		{
			++ret;
			break;
		}
		++ret;
		p_chazhao = p_chazhao->next;
	}
	if (p_chazhao == NULL)
		return 0;
	else
		return ret;
}
#endif


void  nizhi(LinkList L)            //逆置链表
{
	int data_number = List_lenght(L);
	void** pp_data = malloc(sizeof(void*) * data_number);
	LNode* p_data = L->next;
	for (int i = 0; i < data_number; ++i)
	{
		pp_data[i] = p_data->data;
		p_data = p_data->next;
	}
	p_data = L->next;
	for (int i = data_number-1; i > -1; --i)
	{
		p_data->data = pp_data[i];
		p_data = p_data->next;
	}
}