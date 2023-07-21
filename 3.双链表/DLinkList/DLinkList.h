#ifndef DLINKLIST
#include <stdbool.h>

#define CHARU
#define PRINT_DATA
#define SHANCHU

typedef  struct DNode  DNode, * DLinkList;
typedef  enum weizhi { qian, hou }weizhi;


DLinkList createDLinkList(void);  //创建双链表
bool isEmpty(DLinkList L);        //判断链表是否为空

bool charu(DLinkList L, void* data1, void* data2, weizhi qian_or_hou);
								  //将data2插入到data1之前或之后
void qiancha(DLinkList L, void* data); //前插
void houcha(DLinkList L, void* data);  //后插



void print_data(DLinkList L); //打印双向链表
							  //需要定义宏PRINT_DATA
							  //需要定义函数void print(void*data);


								//需要定义函数void free_data(void*data);
								//需要定义宏SHANCHU
void delete_qianorhou_node(DLinkList L, void* data, weizhi qianorhou);
								//删除给定数据之前或之后的元素
void free_list(DLinkList L);	//删除链表
#endif
