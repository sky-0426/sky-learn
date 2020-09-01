#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
//��ʽ�ṹ����ʾ����
typedef struct QListNode
{
	struct QListNode* next;
	DataType data;
}QueueNode;
//���еĽṹ
typedef struct Queue
{
	QueueNode* front;//��ͷָ��
	QueueNode* rear;//��βָ��
}Queue;


// ��ʼ������
void QueueInit(Queue* q);
// ��β�����
void QueuePush(Queue* q, DataType data);
// ��ͷ������
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ��
DataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ��
DataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q);
// ���ٶ���
void QueueDestroy(Queue* q);
