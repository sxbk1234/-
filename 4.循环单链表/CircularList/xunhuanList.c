#include "xunhuanList.h"
#include <stdlib.h>

struct LNode {
	void* data;
	struct LNode* next;
};


xunhuanlist createList(void)   //������
{
	xunhuanlist L = (xunhuanlist)malloc(sizeof(LNode));
	L->data = NULL;
	L->next = NULL;

	return L;
}

bool iskong(xunhuanlist L)     //�ж�ѭ�������Ƿ�Ϊ��
{
	return L->next == NULL;
}

bool isbiaowei(xunhuanlist L, void* data) //�жϸ��������ڽڵ��Ƿ�Ϊ��β
{
	LNode* p_node = L->next;
	while (1)
	{
		if (p_node->data == data)
			break;

		p_node = p_node->next;
	}

	if (p_node->next == L->next)
		return true;
	else
		return false;
}


static LNode* createNode(void* data)  //����ڵ�
{
	LNode* p_node = (LNode*)malloc(sizeof(LNode));
	p_node->data = data;
	p_node->next = NULL;

	return p_node;
}

void toucha(xunhuanlist L, void* data)    //ͷ��
{
	LNode* p_node = createNode(data);
	if (L->next == NULL)
	{
		p_node->next = p_node;
		L->next = p_node;

		return;
	}

	p_node->next = L->next;
	LNode* p_xunzhao = L->next;

	while (L->next != p_xunzhao->next)
		p_xunzhao = p_xunzhao->next;

	p_xunzhao->next = p_node;
	L->next = p_node;
}

void weicha(xunhuanlist L, void* data)    //β��
{
	LNode* p_node = createNode(data);

	if (L->next == NULL)
	{
		p_node->next = p_node;
		L->next = p_node;

		return;
	}

	p_node->next = L->next;
	LNode* p_xunzhao = L->next;

	while (p_xunzhao->next != L->next)
		p_xunzhao = p_xunzhao->next;

	p_xunzhao->next = p_node;
}


#ifdef PRINT_DATA	
void print(void* data);
void print_data(xunhuanlist L)   //��ӡ����
{
	LNode* p_data = L->next;

	if (p_data == NULL) return;

	while (p_data->next != L->next)
	{
		print(p_data->data);
		p_data = p_data->next;
	}

	print(p_data->data);
	putchar('\n');
}

#endif