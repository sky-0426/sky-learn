#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"
void test1()
{
	SeqList L;
	SeqListInit(&L);
	SeqListPushBack(&L, 1);
	SeqListPushBack(&L, 2);
	SeqListPushBack(&L, 3);
	SeqListPushBack(&L, 4);
	SeqListPushBack(&L, 5);
	SeqListPrint(&L);
}
int main()
{
	test1();
	return 0;
}