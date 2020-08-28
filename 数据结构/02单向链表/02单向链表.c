#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 动态申请一个节点
ListNode* BuyListNode(DateType x)
{
	//申请空间
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	//数据域、指针域赋值
	node->date = x;
	node->next = NULL;

	return node;
}
// 单链表打印
void ListPrint(ListNode* plist)
{
	ListNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 单链表尾插
void ListPushBack(ListNode** pplist, DateType x)
{
	ListNode* newnode = BuyListNode(x);
	if (*pplist == NULL)//判断链表是否为空
	{
		*pplist = newnode;//为空，则直接插入
	}
	else//不为空，寻找链表位进行插入操作
	{
		//定义tail寻找链表尾
		ListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//尾部插入新结点
		tail->next = newnode;
	}
}
// 单链表的头插
void ListPushFront(ListNode** pplist, DateType x)
{ 
	//申请一个新节点
	ListNode* newnode = BuyListNode(x);
	//1、空
	//2、非空
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
}
// 单链表的尾删 
void ListPopBack(ListNode** pplist)
{
	//定义pre指向链表尾的前一个结点
	ListNode* pre = NULL;
	//定义tail寻找链表尾
	ListNode* tail = *pplist;
	//1、空、只有一个结点
	//2、两个及以上得结点

	//链表为空或者只有一个结点
	if (tail == NULL || tail->next == NULL)
	{
		free(tail);
		*pplist = NULL;
	}
	else//有多个结点
	{
		while (tail->next != NULL)
		{
			pre = tail;
			tail = tail->next;
		}
		//将新的表尾置空
		pre->next = NULL;
		//释放掉原来的表尾结点
		free(tail);
	}
}
// 单链表头删
void ListPopFront(ListNode** pplist)
{
	//1、空
	//2、只有一个结点
	//3、正常情况
	ListNode* plist = *pplist;
	if (plist == NULL)
	{
		return;
	}
	else if (plist->next == NULL)
	{
		free(plist);
		*pplist = NULL;
	}
	else
	{
		ListNode* next = plist->next;
		free(plist);
		*pplist = next;
	}
}
// 单链表查找
ListNode* ListFind(ListNode* plist, DateType x)
{
	ListNode* cur = plist;
	while (cur != NULL)
	{
		if (cur->date == x )
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// 单链表在pos位置之后插入x
void ListInsertAfter(ListNode* pos, DateType x)
{
	ListNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
// 单链表删除pos位置之后的值
void ListEraseAfter(ListNode* pos)
{
	ListNode* next = pos->next;
	if (next != NULL)
	{
		pos->next = next->next;
		free(next);
	}
}
//单链表的销毁
void ListDestory(ListNode** pplist)
{
	ListNode* cur = *pplist;
	while (cur)
	{
		ListNode* next = cur->next;
		free(cur);
		cur->next;
	}
	*pplist = NULL;
}