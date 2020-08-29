#include "DoubleList.h"

void test01()
{
	ListNode* list = ListCreate();
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPrint(list);
	ListPopBack(list);
	ListPrint(list);
	ListPopFront(list);
	ListPrint(list);
	ListPopFront(list);
	ListPrint(list);
	ListPopFront(list);
	ListPrint(list);
	ListPopFront(list);
}

int main()
{
	test01();
	return 0;
}