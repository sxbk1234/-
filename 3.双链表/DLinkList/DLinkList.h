#ifndef DLINKLIST
#include <stdbool.h>

#define CHARU
#define PRINT_DATA
#define SHANCHU

typedef  struct DNode  DNode, * DLinkList;
typedef  enum weizhi { qian, hou }weizhi;


DLinkList createDLinkList(void);  //����˫����
bool isEmpty(DLinkList L);        //�ж������Ƿ�Ϊ��

bool charu(DLinkList L, void* data1, void* data2, weizhi qian_or_hou);
								  //��data2���뵽data1֮ǰ��֮��
void qiancha(DLinkList L, void* data); //ǰ��
void houcha(DLinkList L, void* data);  //���



void print_data(DLinkList L); //��ӡ˫������
							  //��Ҫ�����PRINT_DATA
							  //��Ҫ���庯��void print(void*data);


								//��Ҫ���庯��void free_data(void*data);
								//��Ҫ�����SHANCHU
void delete_qianorhou_node(DLinkList L, void* data, weizhi qianorhou);
								//ɾ����������֮ǰ��֮���Ԫ��
void free_list(DLinkList L);	//ɾ������
#endif
