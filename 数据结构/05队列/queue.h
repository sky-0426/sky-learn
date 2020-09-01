#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
//链式结构：表示队列
typedef struct QListNode
{
	struct QListNode* next;
	DataType data;
}QueueNode;
//队列的结构
typedef struct Queue
{
	QueueNode* front;//队头指针
	QueueNode* rear;//队尾指针
}Queue;


// 初始化队列
void QueueInit(Queue* q);
// 队尾入队列
void QueuePush(Queue* q, DataType data);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素
DataType QueueFront(Queue* q);
// 获取队列队尾元素
DataType QueueBack(Queue* q);
// 获取队列中有效元素个数
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);
