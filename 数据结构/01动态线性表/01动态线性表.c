#include "DynamicArray.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// 顺序表初始化
void SeqListInit(SeqList* psl)
{
	assert(psl);
	psl->array = NULL;
	psl->capicity = 0;
	psl->size = 0;
}
// 顺序表销毁
void SeqListDestory(SeqList* psl)
{
	assert(psl);
	free(psl->array);
	psl->array = NULL;
	psl->capicity = psl->size = 0;
}
// 顺序表打印
void SeqListPrint(SeqList* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}
// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->size == psl->capicity)
	{
		int newcapicity = psl->capicity * 2;
		psl->array = (SLDataType*)realloc(psl->array, sizeof(SLDataType)*newcapicity);
		psl->capicity = newcapicity;
	}
}
// 顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	SeqListInsert(psl, psl->size, x);
}
// 顺序表尾删
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	SeqListErase(psl, psl->size);
}
// 顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	SeqListInsert(psl, 0, x);
}
// 顺序表头删
void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	SeqListErase(psl, 0);
}
// 顺序表查找
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(pos<=psl->size);
	CheckCapacity(psl);//检查线性表是否已满，若满了则进行扩容操作
	int end = psl->size;
	while (end > pos)
	{
		psl->array[end] = psl->array[end - 1];
		end--;
	}
	psl->array[pos] = x;
	psl->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, int pos)
{
	assert(psl);
	assert(pos<psl->size);
	int start = pos + 1;
	while (start < psl->size)
	{
		psl->array[start - 1] = psl->array[start];
		start++;
	}
	psl->size--;
}

