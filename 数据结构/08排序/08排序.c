#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[] = { 3,6,2,5,7,4,9,8,1 };
	int len = sizeof(a) / sizeof(a[0]);

	//InsertSort(a, len);

	//ShellSort(a, len);

	//SelectSort(a, len);

	//HeapSort(a, len);

	//BubbleSort(a, len);
	
	//QuickSort(a, 0, len-1);

	//MergingSort(a, len);

	CountSort(a, len);

	PrintSort(a,len);

	return 0;
}
//