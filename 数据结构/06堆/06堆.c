#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

//向上调整算法
void AdjustUp(DataType* a, int n, int child)
{
	int parent = (child-1)/2;
	while (child > 0)
	{
		//如果孩子大于双亲，进行交换
		if (a[child] > a[parent])
		{
			DataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			//调整，进行下一次交换
			child = parent;
			parent= (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//向下调整算法:左子树是小堆，右子树也是小堆
void AdjustDown(DataType* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找出左右孩子中小的那一个
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		//如果孩子比双亲还小，则将小的一个孩子结点与双亲结点进行交换
		if (a[parent] > a[child])
		{
			DataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			//调整，进行下一次交换
			parent = child;
			child = parent * 2 + 1;
		}
		else//孩子比双亲大，则终止调整
		{
			break;
		}
	}
}
// 堆的构建
void HeapCreate(Heap* hp, DataType* a, int n)
{
	hp->arr = (DataType*)malloc(sizeof(DataType)*n);
	hp->size = n;
	hp->capacity = n;

	//建堆:调用向下调整算法，从最后一个结点的双亲开始
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->arr, hp->size, i);
	}
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	free(hp->arr);
	hp->arr = NULL;
	hp->size = hp->capacity = 0;
}
// 堆的插入
void HeapPush(Heap* hp, DataType x)
{
	//检查容量
	if (hp->size == hp->capacity)
	{
		hp->capacity *= 2;
		hp->arr = (DataType*)realloc(hp->arr, sizeof(DataType)*hp->capacity);
	}
	//尾插
	hp->arr[hp->size] = x;
	hp->size++;
	//向上调整
	AdjustUp(hp->arr, hp->size, hp->size-1);
}
// 堆的删除
void HeapPop(Heap* hp)
{
	//交换
	DataType tmp = hp->arr[0];
	hp->arr[0] = hp->arr[hp->size - 1];
	hp->arr[hp->size - 1] = tmp;
	//向下调整
	AdjustDown(hp->arr, hp->size, 0);
}
// 取堆顶的数据
DataType HeapTop(Heap* hp)
{
	return hp->arr[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	return hp->size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	if (hp->size == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
// 对数组进行堆排序
// 升序建小堆，降序建大堆
void HeapSort(int* a, int n)
{
	//排序需要建大堆：
	//因为每次都会把堆顶元素拿出来放到当前堆的最后一个位置
	//相对于每次都会把剩余元素当中的最大值(即堆顶元素)找出来，放到当前堆的最后一个位置
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	while (n - 1 > 0)
	{
		DataType tmp = a[0];
		a[0] = a[n - 1];
		a[n - 1] = tmp;
		//调堆，选次大的数
		AdjustDown(a, n - 1, 0);
		n--;
	}
}
