#pragma once
typedef int DateType;
//链表结点
typedef struct ListNode
{
	DateType date;
	struct ListNode* next;
}ListNode;

// 动态申请一个节点
ListNode* BuyListNode(DateType x);
// 单链表打印
void ListPrint(ListNode* plist);
// 单链表尾插
void ListPushBack(ListNode** pplist, DateType x);
// 单链表的头插
void ListPushFront(ListNode** pplist, DateType x);
// 单链表的尾删
void ListPopBack(ListNode** pplist);
// 单链表头删
void ListPopFront(ListNode** pplist);
// 单链表查找
ListNode* ListFind(ListNode* plist, DateType x);
// 单链表在pos位置之后插入x
void ListInsertAfter(ListNode* pos, DateType x);
// 单链表删除pos位置之后的值
void ListEraseAfter(ListNode* pos);
//单链表的销毁
void ListDestory(ListNode** pplist);