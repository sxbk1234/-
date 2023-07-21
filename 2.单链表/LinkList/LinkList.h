#ifndef LINKLIST
#define LINKLIST
#include <stdbool.h>
#define PRINT_LIST
#define ANZHICHAZHAO

struct LNode;
typedef struct LNode LNode,*LinkList;
typedef enum weizhi { qian, hou } weizhi;


LinkList createLinkList(void);		//创建一个空链表
bool  IsEmpty(LinkList L);			//判断链表是否为空
void  toucha(LinkList L, void* data);			//头插
void  weicha(LinkList L, void* data);			//尾插
bool  weixucha(LinkList L, void* data, int weixu,weizhi qian_or_hou);	//位序
int   List_lenght(LinkList L);      //链表长度
void  nizhi(LinkList L);            //逆置链表

void* weixuchazhao(LinkList L, int i);			//按位序查找
int   anzhichazhao(LinkList L, void* data);     //按值查找
												//需要定义bool xiangdeng(void* data1, void* data2);
												//需要定义宏ANZHICHAZHAO

void print_list(LinkList L);		//打印链表
									//需要定义宏 PRINT_LIST
									//需要定义函数 void print(void*);

									//需要定义bool free_data(void*data)函数
									//需要定义宏SHANCHU
bool weishan(LinkList L);			//尾删
bool toushan(LinkList L);           //头删
bool weixushan(LinkList L,int weixu);	//位序删
void yuansu_shan(LinkList L, void** data); //元素删
									       //需要定义bool xiangdeng(void* data1, void* data2);
										   //需要定义宏YUANSU_SHAN
#endif
