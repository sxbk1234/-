#ifndef _LIST
#define _LIST

#define PRINT_DATA
#define SHANCHU

typedef struct node_head *list;
typedef enum  weizhi { qian, hou } weizhi;

list createList(void);     //����һ��˫��ѭ������
void toucha(list L, void*);//ͷ��
void weicha(list L, void*);//β��
void weixucha(list L, void*data ,weizhi qianorhou, int weixu); // ����λ���������
int  data_number(list L);   //�����������������
void* weixu_chazhao(list L, int weixu);  //����λ�򷵻�����
void  genhuan_data(list L, void* data1, int weixu);    //����λ�򴦵�����

void print_data(list L);    //��ӡ����
					       //��Ҫ�����PRINT_DATA
						   //��Ҫ���庯��void print(void*data);

										//��Ҫ�����SHANCHU
										//��Ҫ���庯��void free_data(void*data);
void data_delete(list L, void* data);	//���ݸ���������ɾ���ڵ�
void free_list(list L);					//�ͷ�����
#endif