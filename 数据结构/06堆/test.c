#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

//TopK���⡪���ҳ�N���������/��С��ǰK��
//����С�ġ���С��
//�����ġ������
void PrintTopK(int* a, int n, int k)
{
	Heap hp;
	//��������K��Ԫ�صĶ�
	HeapCreate(&hp, a, k);
	for (int i = k; i < n; i++)
	{
		//ÿ�κͶѶ�Ԫ�رȽϣ����ڶѶ�Ԫ�أ�ɾ���Ѷ������µ�Ԫ��
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