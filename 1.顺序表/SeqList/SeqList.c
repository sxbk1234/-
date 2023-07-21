#include "SeqList.h"
#include <stdlib.h>

struct seqlist
{
	void** data;
	int    MaxSize;
	int    length;
};


//����˳���
SeqList* CreateList(int MaxSize)
{
	SeqList* L_p = (SeqList*)malloc(sizeof(SeqList));
	L_p->MaxSize = MaxSize;
	L_p->length = 0;
	L_p->data = (void**)malloc(sizeof(void*) * MaxSize);


	return L_p;
}




//��˳�������
void IncreaseSize(SeqList* L, int add_len)
{
	void** p_data = L->data;
	L->data = (void**)malloc(sizeof(void*) * (add_len + L->MaxSize));

	for (int i = 0; i < L->length; ++i)
	{
		(L->data)[i] = p_data[i];
	}

	L->MaxSize += add_len;
	free(p_data);
}

//�������
bool ListInsert(SeqList* L, void* data, int i, enum position weizhi)					
{
	if (i < 1 || i>L->length ) return false;
	if (L->length == L->MaxSize)
		IncreaseSize(L, 10);

	int dingwei = i - 1;
	if (weizhi == hou)
	{
		for (int hou = L->length; hou > dingwei + 1; --hou)
		{
			L->data[hou] = L->data[hou - 1];
		}
		L->data[dingwei + 1] = data;
	}
	else
	{
		for (int hou = L->length; hou > dingwei; --hou)
		{
			L->data[hou] = L->data[hou - 1];
		}
		L->data[dingwei] = data;
	}
	++L->length;
	return true;
}

//˳�����
void shunxu_insert(SeqList* L, void* data)			
{
	if (L->length == L->MaxSize)
	{
		IncreaseSize(L, 10);
		
	}

	L->data[L->length] = data;
	++L->length;
}


//������ӡ����
//��Ҫ���庯��void print(void*);

#ifdef PRINT_LIST
void print(void* data);
void print_list(SeqList* L)
{
	for (int i = 0; i < L->length; ++i)
	{
		print(L->data[i]);
	}
	putchar('\n');
}

#endif


//�������ݵ�����
int  data_number(SeqList* L)						
{
	return L->length;
}

//����i��Ԫ��ɾ��������e����
bool ListDelete(SeqList* L, void** data, int i)
{
	if (i<1 || i> L->length)
	{
		*data = NULL;
		return false;
	}

	*data = L->data[i - 1];

	for (int d = i - 1; d < L->length - 1; ++d)
	{
		L->data[d] = L->data[d + 1];
	}
	--L->length;

	return true;
}


//����iλ�õ�Ԫ��
void* GetElem(SeqList* L, int i)
{
	if (i < 1 || i>L->length) return NULL;

	return L->data[i - 1];
}

//���ҵ�һ��Ԫ��ֵ����e��Ԫ�أ���������λ��
#ifdef LOCATEELEM
bool xiangdeng(void*, void*);
int LocateElem(SeqList* L, void* e)
{
	for (int i = 0; i < L->length; ++i)
	{
		if (xiangdeng(L->data[i], e))
			return i + 1;
	}

	return -1;
}
#endif