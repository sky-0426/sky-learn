#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//直接插入
void InsertSort(int* a, int n)
{
	//多趟排序
	//控制end的位置从0走到n-2
	for (int i = 0; i < n - 1; i++)
	{
		//单趟排序
		//在[0,end]区间中插入tmp，依旧有序
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
//希尔排序
void ShellSort(int* a, int n)
{
	//gap>1时，为预排序，接近有序
	//gap=1时，为直接插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//3个间隔为gap的组同时交叉排序
		for (int i = 0; i < n - gap; i++)
		{
			//间隔为gap的预排序
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void Swap(int* a, int* b)
{
	int* tmp = *a;
	*a = *b;
	*b = tmp;
}
//直接选择排序
//一次选择两个数，最小的放前边，最大的放后边
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//[begin,end]区间选出一个最小的一个最大的数的下标
		int min = begin, max = end;
		for (int i = begin; i <= end;  i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		Swap(&a[begin], &a[min]);
		if (begin == max)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}
//向下调整算法
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出左右孩子中大的那一个
		if (child + 1 < n&&a[child + 1] > a[child])
		{
			child++;
		}
		//比较孩子比父亲大，交换，继续向下调整
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//堆排序
void HeapSort(int* a, int n)
{
	//排升序建大堆 O(n)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		//把堆顶元素依次换到最后
		Swap(&a[0], &a[end]);
		//调整选出剩下数中，最大的
		AdjustDown(a, end, 0);
		end--;
	}
}
//冒泡排序
void BubbleSort(int* a, int n)
{
	//控制循环的次数
	for (int i = 0; i < n; i++)
	{
		//flag用来标记，初始化为0
		int flag = 0;
		//n-1是最后一个元素的下标，n-1-1是倒数第二个元素的下标
		for (int j = n - 1 - 1; j >= i; j--)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				//若有数据交换则置flag为1
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
//快速排序
//左右指针法
int PartSort1(int* a, int begin, int end)
{
	//end做key,左边先走；begin做key，右边先走
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		//begin找大于key的
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//end找小于key的
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}
//挖坑法
int PartSort2(int* a, int begin, int end)
{
	//用下标为0的那个位置做坑
	int key = a[begin];
	//从两端交替向中间扫描
	while (begin < end)
	{
		//end找小于key的
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		//将下标为end的元素与坑交换，end做新的坑
		a[begin] = a[end];
		//begin找大于key的
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//将下标为begin的元素与坑交换，begin又做新的坑
		a[end] = a[begin];
	}
	a[begin] = key;
	return begin;
}
//前后指针法
int PartSort3(int* a, int begin, int end)
{
	int pre = begin - 1;
	int cur = begin;
	int key = a[end];
	//cur指针遇到key的位置就结束
	while (cur < end)
	{
		if (a[cur] < key && ++pre != cur)
		{
			Swap(&a[pre], &a[cur]);
		}
		cur++;
	}
	pre++;
	Swap(&a[pre], &a[end]);
	return pre;
}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return; 
	}
	//[begin,keyindex-1] keyindex [keyindex+1,end]
	//int keyindex = PartSort1(a, begin, end);
	//int keyindex = PartSort2(a, begin, end);
	int keyindex = PartSort3(a, begin, end);
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);
} 
//归并排序
void MSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	//先划分
	int mid = (begin + end) >> 1;
	MSort(a, begin, mid, tmp);
	MSort(a, mid + 1, end, tmp);
	//归并两段有序区间
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index] = a[begin1];
			index++;
			begin1++;
		}
		else
		{
			tmp[index] = a[begin2];
			index++;
			begin2++;
		}
	}
	if (begin1 <= end1)
	{
		while (begin1 <= end1)
		{
			tmp[index] = a[begin1];
			index++;
			begin1++;
		}
	}
	else
	{
		while (begin2 <= end2)
		{
			tmp[index] = a[begin2];
			index++;
			begin2++;
		}
	}
	memcpy(a+begin, tmp+begin, sizeof(int)*(end-begin+1));
}
void MergingSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	MSort(a, 0, n - 1, tmp);
	free(tmp);
}
//计数排序
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	//找出最大的和最小的
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	//申请计数空间
	int length = max - min + 1;
	int* countarr = (int*)malloc(sizeof(int)*length);
	//计数数组初始化为0
	memset(countarr, 0, sizeof(int)*length);
	//统计次数
	for (int i = 0; i < n; i++)
	{
		int index = a[i];
		countarr[index - min]++;
	}
	//根据次数进行排序
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (countarr[i] == 0)
		{
			break;
		}
		else
		{
			a[j] = i + min;
			j++;
		}
	}
}