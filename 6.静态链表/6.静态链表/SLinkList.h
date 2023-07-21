#ifndef _SLINKLIST
#define _SLINKLIST

typedef  struct  node  *slinklist;

slinklist createList(int listsize);			//创建静态链表
void  charu(slinklist L, void* data);		//插入
void  shanchu(slinklist L, int weixu);					//根据位序删除

void print(slinklist L);					//打印链表
#endif
