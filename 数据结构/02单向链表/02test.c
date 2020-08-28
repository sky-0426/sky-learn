#include <stdio.h>

#include "LinkList.h"


void test()
{
	ListNode* plist = NULL;
	//Î²²å
	ListPushBack(&plist, 1);
	ListPushBack(&plist, 2);
	ListPushBack(&plist, 3);
	ListPushBack(&plist, 4);
	ListPrint(plist);
	//Î²É¾
	ListPopBack(&plist);
	ListPrint(plist);
	ListPopBack(&plist);
	ListPrint(plist);
	ListPopBack(&plist);
	ListPrint(plist);
	ListPopBack(&plist);
	ListPrint(plist);
	//Í·²å
	ListPushFront(&plist, 0);
	ListPrint(plist);


}
int main()
{
	test();
	return 0;
}