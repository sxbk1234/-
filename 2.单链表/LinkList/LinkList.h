#ifndef LINKLIST
#define LINKLIST
#include <stdbool.h>
#define PRINT_LIST
#define ANZHICHAZHAO

struct LNode;
typedef struct LNode LNode,*LinkList;
typedef enum weizhi { qian, hou } weizhi;


LinkList createLinkList(void);		//����һ��������
bool  IsEmpty(LinkList L);			//�ж������Ƿ�Ϊ��
void  toucha(LinkList L, void* data);			//ͷ��
void  weicha(LinkList L, void* data);			//β��
bool  weixucha(LinkList L, void* data, int weixu,weizhi qian_or_hou);	//λ��
int   List_lenght(LinkList L);      //������
void  nizhi(LinkList L);            //��������

void* weixuchazhao(LinkList L, int i);			//��λ�����
int   anzhichazhao(LinkList L, void* data);     //��ֵ����
												//��Ҫ����bool xiangdeng(void* data1, void* data2);
												//��Ҫ�����ANZHICHAZHAO

void print_list(LinkList L);		//��ӡ����
									//��Ҫ����� PRINT_LIST
									//��Ҫ���庯�� void print(void*);

									//��Ҫ����bool free_data(void*data)����
									//��Ҫ�����SHANCHU
bool weishan(LinkList L);			//βɾ
bool toushan(LinkList L);           //ͷɾ
bool weixushan(LinkList L,int weixu);	//λ��ɾ
void yuansu_shan(LinkList L, void** data); //Ԫ��ɾ
									       //��Ҫ����bool xiangdeng(void* data1, void* data2);
										   //��Ҫ�����YUANSU_SHAN
#endif
