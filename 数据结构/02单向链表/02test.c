#include <stdio.h>

#include "LinkList.h"


void test()
{
	ListNode* plist = NULL;
	//β��
	ListPushBack(&plist, 1);
	ListPushBack(&plist, 2);
	ListPushBack(&plist, 3);
	ListPushBack(&plist, 4);
	ListPrint(plist);
	//βɾ
	ListPopBack(&plist);
	ListPrint(plist);
	ListPopBack(&plist);
	ListPrint(plist);
	ListPopBack(&plist);
	ListPrint(plist);
	ListPopBack(&plist);
	ListPrint(plist);
	//ͷ��
	ListPushFront(&plist, 0);
	ListPrint(plist);


}
int main()
{
	test();
	return 0;
}