#ifndef _SLINKLIST
#define _SLINKLIST

typedef  struct  node  *slinklist;

slinklist createList(int listsize);			//������̬����
void  charu(slinklist L, void* data);		//����
void  shanchu(slinklist L, int weixu);					//����λ��ɾ��

void print(slinklist L);					//��ӡ����
#endif
