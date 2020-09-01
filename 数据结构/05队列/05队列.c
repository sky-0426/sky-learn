#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// 初始化队列
void QueueInit(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
}
// 队尾入队列
void QueuePush(Queue* q, DataType data)
{
	//申请结点空间
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	//结点赋值
	newnode->data = data;
	newnode->next;
	//判断队列是否为空
	if (q->front == NULL)
	{
		//为空，直接插入
		q->front = q->rear = newnode;
	}
	else
	{
		//不为空，将新节点插在队尾，重置队尾指针
		q->rear->next = newnode;
		q->rear = newnode;
	}
}
// 队头出队列
void QueuePop(Queue* q)
{
	//判断队列是否为空
	if (q->front == NULL)
	{
		//为空直接return
		return;
	}
	//定义tmp指针暂存队头的下一个指针
	QueueNode* tmp = q->front->next;
	//释放队头结点
	free(q->front);
	//重置新的队头
	q->front = tmp;
}
// 获取队列头部元素
DataType QueueFront(Queue* q)
{
	return q->front->data;
}
// 获取队列队尾元素
DataType QueueBack(Queue* q)
{
	return q->rear->data;
}
// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
	QueueNode* cur;
	//计数器
	int count = 0;
	//循环遍历队列
	for (cur = q->front; cur; cur = cur->next)
	{
		count++;
	}
	return count;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q)
{
	return q->front == NULL;
}
// 销毁队列
void QueueDestroy(Queue* q)
{
	if (q->front == NULL)
	{
		return;
	}
	while (q->front)
	{
		QueuePop(q);
	}
}