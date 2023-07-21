#ifndef _XUNHUANLIST
#define _XUNHUANLIST
#include <stdbool.h>

#define PRINT_DATA

typedef struct LNode LNode,* xunhuanlist;

xunhuanlist createList(void);   //创建表
bool iskong(xunhuanlist L);     //判断循环链表是否为空
bool isbiaowei(xunhuanlist L, void* data); //判断该数据所在节点是否为表尾
void toucha(xunhuanlist L, void* data);    //头插
void weicha(xunhuanlist L, void* data);    //尾插

void print_data(xunhuanlist L);   //打印链表
								  //需要定义宏PRINT_DATA
								  //需要定义函数void print(void*data);
#endif
