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
//ֱ�Ӳ���
void InsertSort(int* a, int n)
{
	//��������
	//����end��λ�ô�0�ߵ�n-2
	for (int i = 0; i < n - 1; i++)
	{
		//��������
		//��[0,end]�����в���tmp����������
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
//ϣ������
void ShellSort(int* a, int n)
{
	//gap>1ʱ��ΪԤ���򣬽ӽ�����
	//gap=1ʱ��Ϊֱ�Ӳ�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//3�����Ϊgap����ͬʱ��������
		for (int i = 0; i < n - gap; i++)
		{
			//���Ϊgap��Ԥ����
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
//ֱ��ѡ������
//һ��ѡ������������С�ķ�ǰ�ߣ����ķź��
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//[begin,end]����ѡ��һ����С��һ�����������±�
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
//���µ����㷨
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//ѡ�����Һ����д����һ��
		if (child + 1 < n&&a[child + 1] > a[child])
		{
			child++;
		}
		//�ȽϺ��ӱȸ��״󣬽������������µ���
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
//������
void HeapSort(int* a, int n)
{
	//�����򽨴�� O(n)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		//�ѶѶ�Ԫ�����λ������
		Swap(&a[0], &a[end]);
		//����ѡ��ʣ�����У�����
		AdjustDown(a, end, 0);
		end--;
	}
}
//ð������
void BubbleSort(int* a, int n)
{
	//����ѭ���Ĵ���
	for (int i = 0; i < n; i++)
	{
		//flag������ǣ���ʼ��Ϊ0
		int flag = 0;
		//n-1�����һ��Ԫ�ص��±꣬n-1-1�ǵ����ڶ���Ԫ�ص��±�
		for (int j = n - 1 - 1; j >= i; j--)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				//�������ݽ�������flagΪ1
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
//��������
//����ָ�뷨
int PartSort1(int* a, int begin, int end)
{
	//end��key,������ߣ�begin��key���ұ�����
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		//begin�Ҵ���key��
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//end��С��key��
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}
//�ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	//���±�Ϊ0���Ǹ�λ������
	int key = a[begin];
	//�����˽������м�ɨ��
	while (begin < end)
	{
		//end��С��key��
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		//���±�Ϊend��Ԫ����ӽ�����end���µĿ�
		a[begin] = a[end];
		//begin�Ҵ���key��
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//���±�Ϊbegin��Ԫ����ӽ�����begin�����µĿ�
		a[end] = a[begin];
	}
	a[begin] = key;
	return begin;
}
//ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end)
{
	int pre = begin - 1;
	int cur = begin;
	int key = a[end];
	//curָ������key��λ�þͽ���
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
//�鲢����
void MSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	//�Ȼ���
	int mid = (begin + end) >> 1;
	MSort(a, begin, mid, tmp);
	MSort(a, mid + 1, end, tmp);
	//�鲢������������
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
//��������
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	//�ҳ����ĺ���С��
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
	//��������ռ�
	int length = max - min + 1;
	int* countarr = (int*)malloc(sizeof(int)*length);
	//���������ʼ��Ϊ0
	memset(countarr, 0, sizeof(int)*length);
	//ͳ�ƴ���
	for (int i = 0; i < n; i++)
	{
		int index = a[i];
		countarr[index - min]++;
	}
	//���ݴ�����������
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