#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

//TopK问题——找出N个数中最大/最小的前K个
//找最小的——小堆
//找最大的——大堆
void PrintTopK(int* a, int n, int k)
{
	Heap hp;
	//建立含有K个元素的堆
	HeapCreate(&hp, a, k);
	for (int i = k; i < n; i++)
	{
		//每次和堆顶元素比较，大于堆顶元素，删除堆顶插入新的元素
		HeapPop(&hp);
		HeapPush(&hp, a[i]);
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}
int main()
{
	int a[10] = { 27,15,19,34,65,37,25,49,28,18 };
	//HeapSort(a, 10);
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d ", a[i]);
	//}
	PrintTopK(a, 10, 5);
	return 0;
}