#pragma once
typedef int DataType;
typedef struct Heap
{
	DataType* arr;
	int size;
	int capacity;
}Heap;

// �ѵĹ���
void HeapCreate(Heap* hp, DataType* a, int n);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, DataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
DataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
// ��������ж�����
void HeapSort(int* a, int n);