#ifndef _LIST
#define _LIST

#define PRINT_DATA
#define SHANCHU

typedef struct node_head *list;
typedef enum  weizhi { qian, hou } weizhi;

list createList(void);     //创建一个双向循环链表
void toucha(list L, void*);//头插
void weicha(list L, void*);//尾插
void weixucha(list L, void*data ,weizhi qianorhou, int weixu); // 根据位序插入数据
int  data_number(list L);   //返回链表的数据数量
void* weixu_chazhao(list L, int weixu);  //根据位序返回数据
void  genhuan_data(list L, void* data1, int weixu);    //更换位序处的数据

void print_data(list L);    //打印链表
					       //需要定义宏PRINT_DATA
						   //需要定义函数void print(void*data);

										//需要定义宏SHANCHU
										//需要定义函数void free_data(void*data);
void data_delete(list L, void* data);	//根据给出的数据删除节点
void free_list(list L);					//释放链表
#endif