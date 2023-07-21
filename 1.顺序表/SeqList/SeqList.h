#ifndef SEQLIST
#define SEQLIST
#include <stdbool.h>
#define PRINT_LIST
#define	LOCATEELEM

struct seqlist;
typedef struct seqlist SeqList;
enum position{ qian ,hou };

SeqList* CreateList(int MaxSize);					//����˳���
void IncreaseSize(SeqList* L, int add_len);			//��˳�������
bool ListInsert(SeqList* L, void* data ,int i,enum position weizhi);					
													//�������
void shunxu_insert(SeqList* L, void* data);			//˳�����
bool ListDelete(SeqList* L, void** data,int i);		//����i��Ԫ��ɾ��������e����
int  data_number(SeqList* L);						//�������ݵ�����
void* GetElem(SeqList* L, int i);                   //����iλ�õ�Ԫ��


void print_list(SeqList* L);						//������ӡ����
													//��Ҫ���庯��void print(void*);
													//��Ҫ�����PRINT_LIST
				
int LocateElem(SeqList* L, void* e);	//���ҵ�һ��Ԫ��ֵ����e��Ԫ�أ���������λ��
										//��Ҫ���庯��bool xiangdeng(void*,void*);
										//��Ҫ�����LOCATEELEM

#endif