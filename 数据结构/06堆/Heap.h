#pragma once
typedef int DataType;
typedef struct Heap
{
	DataType* arr;
	int size;
	int capacity;
}Heap;

// 堆的构建
void HeapCreate(Heap* hp, DataType* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, DataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
DataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
// 对数组进行堆排序
void HeapSort(int* a, int n);