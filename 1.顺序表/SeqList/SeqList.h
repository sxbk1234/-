#ifndef SEQLIST
#define SEQLIST
#include <stdbool.h>
#define PRINT_LIST
#define	LOCATEELEM

struct seqlist;
typedef struct seqlist SeqList;
enum position{ qian ,hou };

SeqList* CreateList(int MaxSize);					//创建顺序表
void IncreaseSize(SeqList* L, int add_len);			//给顺序表扩容
bool ListInsert(SeqList* L, void* data ,int i,enum position weizhi);					
													//插入操作
void shunxu_insert(SeqList* L, void* data);			//顺序插入
bool ListDelete(SeqList* L, void** data,int i);		//将第i个元素删除，并用e返回
int  data_number(SeqList* L);						//返回数据的数量
void* GetElem(SeqList* L, int i);                   //返回i位置的元素


void print_list(SeqList* L);						//遍历打印数据
													//需要定义函数void print(void*);
													//需要定义宏PRINT_LIST
				
int LocateElem(SeqList* L, void* e);	//查找第一个元素值等于e的元素，并返回其位序
										//需要定义函数bool xiangdeng(void*,void*);
										//需要定义宏LOCATEELEM

#endif