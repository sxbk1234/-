#ifndef _XUNHUANLIST
#define _XUNHUANLIST
#include <stdbool.h>

#define PRINT_DATA

typedef struct LNode LNode,* xunhuanlist;

xunhuanlist createList(void);   //������
bool iskong(xunhuanlist L);     //�ж�ѭ�������Ƿ�Ϊ��
bool isbiaowei(xunhuanlist L, void* data); //�жϸ��������ڽڵ��Ƿ�Ϊ��β
void toucha(xunhuanlist L, void* data);    //ͷ��
void weicha(xunhuanlist L, void* data);    //β��

void print_data(xunhuanlist L);   //��ӡ����
								  //��Ҫ�����PRINT_DATA
								  //��Ҫ���庯��void print(void*data);
#endif
