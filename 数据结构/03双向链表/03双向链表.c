#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "DoubleList.h"

// 创建返回链表的头结点. 
ListNode* ListCreate()
{
	//创建头结点，申请空间
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->pre = head;
	return head;
}
// 双向链表销毁
void ListDestory(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}
// 双向链表打印
void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 双向链表尾插
void ListPushBack(ListNode* phead, DataType x)
{
	//申请一个新节点
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	//数据域赋值
	newnode->data = x;
	//指针域赋值
	newnode->pre = NULL;
	newnode->next = NULL;
	//定义tail指针指向链表的表尾
	ListNode* tail = phead->pre;
	//插入
	tail->next = newnode;
	newnode->pre = tail;
	newnode->next = phead;
	phead->pre = newnode;
}
// 双向链表尾删
void ListPopBack(ListNode* phead)
{
	//断言，链表若为空，则不删除
	assert(phead->next != phead);
	//tail指针指向链表的尾结点
	ListNode* tail = phead->pre;
	//prev指针指向尾结点的前一个结点
	ListNode* prev = tail->pre;
	//释放尾结点
	free(tail);
	//重新连接
	prev->next = phead;
	phead->pre = prev;
}
// 双向链表头插
void ListPushFront(ListNode* phead, DataType x)
{
	//申请一个新节点
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	//数据域赋值
	newnode->data = x;
	//指针域赋值
	newnode->pre = NULL;
	newnode->next = NULL;
	//定义first指针指向链表的头结点
	ListNode* first = phead->next;
	//插入
	phead->next = newnode;
	newnode->pre = phead;
	newnode->next = first;
	first->pre = newnode;
}
// 双向链表头删
void ListPopFront(ListNode* phead)
{
	//断言，链表若为空，则不删除
	assert(phead->next != phead);
	//定义first指针指向链表的头结点
	ListNode* first = phead->next;
	//定义second指针指向链表的头结点
	ListNode* second = first->next;
	//释放结点
	free(first);
	//重新建立连接
	phead->next = second;
	second->pre = phead;
}
// 双向链表查找
ListNode* ListFind(ListNode* phead, DataType x)
{
	ListNode* cur = phead->next;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, DataType x)
{
	ListNode* prev = pos->pre;
	//申请一个新节点
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	//数据域赋值
	newnode->data = x;
	//指针域赋值
	newnode->pre = NULL;
	newnode->next = NULL;
	//插入
	prev->next = newnode;
	newnode->pre = prev;
	newnode->next = pos;
	pos->pre = newnode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode* front = pos->pre;
	ListNode* after = pos->next;
	free(pos);
	front->next = after;
	after->pre = front;
}