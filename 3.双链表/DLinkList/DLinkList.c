#include "DLinkList.h"
#include <stdlib.h>
struct DNode
{
	void* data;
	struct DNode* next;
	struct DNode* prior;	
};



DLinkList createDLinkList(void)  //创建双链表
{
	DNode* p = (DNode*)malloc(sizeof(DNode));
	p->data = NULL;
	p->next = NULL;
	p->prior = NULL;

	return p;
}

bool isEmpty(DLinkList L)        //判断链表是否为空
{
	return L->next == NULL;
}

static DNode* createNode(void* data)
{
	DNode* p = (DNode*)malloc(sizeof(DNode));
	p->data = data;
	p->next = NULL;
	p->prior = NULL;
}

//将data2插入到data1之前或之后
bool charu(DLinkList L, void* data1, void* data2, weizhi qian_or_hou)
{
	DNode* p_dingwei = L->next;
	while (p_dingwei != NULL)
	{
		if (p_dingwei->data == data1)
		{
			DNode* p_charu = createNode(data2);
			if (qian_or_hou == qian)
			{
				p_charu->next = p_dingwei;
				p_charu->prior = p_dingwei->prior;
				p_dingwei->prior = p_charu;

				if (p_charu->prior != NULL)
				{
					p_charu->prior->next = p_charu;
				}
				else
				{
					L->next = p_charu;
				}
			}
			else
			{
				p_charu->next = p_dingwei->next;
				p_charu->prior = p_dingwei;
				p_dingwei->next = p_charu;

				if (p_charu->next != NULL)
				{
				p_charu->next->prior = p_charu;
				}
			}

			return true;
		}

		p_dingwei = p_dingwei->next;
	}

	return false;
}

void qiancha(DLinkList L, void* data) //前插
{
	DNode* p_data = createNode(data);

	if (L->next == NULL)
	{
		L->next = p_data;
		return;
	}

	p_data->next = L->next;
	L->next->prior = p_data;
	L->next = p_data;

}




void houcha(DLinkList L, void* data)  //后插
{
	DNode* p_data = createNode(data);
	DNode* p_dingwei = L;

	if (p_dingwei->next == NULL)
	{
		p_dingwei->next = p_data;
		return;
	}

	while (p_dingwei->next != NULL)
	{
		p_dingwei = p_dingwei->next;
	}
	p_dingwei->next = p_data;
	p_data->prior = p_dingwei;

}


#ifdef PRINT_DATA
void print(void* data);
void print_data(DLinkList L) //打印双向链表
{
	DNode* bianli = L->next;
	while (bianli != NULL)
	{
		print(bianli->data);
		bianli = bianli->next;
	}

	putchar('\n');
}
#endif



#ifdef SHANCHU
void free_data(void* data);
void delete_qianorhou_node(DLinkList L, void* data, weizhi qianorhou)
{
	DNode* p_dingwei = L->next;

	while (p_dingwei != NULL)
	{
		if (p_dingwei->data == data)
		{
			if (qianorhou == qian)
			{
				if (p_dingwei->prior == NULL) return;
				
				DNode* p_delete = p_dingwei->prior;
				p_dingwei->prior = p_delete->prior;

				if (p_dingwei->prior != NULL)
					p_dingwei->prior->next = p_dingwei;

				free_data(p_delete->data);
				free(p_delete);
			}
			else
			{
				if (p_dingwei->next == NULL) return;

				DNode* p_delete = p_dingwei->next;
				p_dingwei->next = p_delete->next;

				if (p_dingwei->next != NULL)
					p_dingwei->next->prior = p_dingwei;

				free_data(p_delete->data);
				free(p_delete);

			}
		}
		p_dingwei = p_dingwei->next;
	}
}



void free_list(DLinkList L)	//删除链表
{
	DNode* p_delete = L->next;
	if (p_delete == NULL) return;
	L->next = NULL;
	DNode* p_hou = p_delete->next;

	while (1)
	{
		free_data(p_delete->data);
		free(p_delete);

		p_delete = p_hou;
		if (p_delete == NULL)
			return;
		else
			p_hou = p_hou->next;
		
	}
}
#endif