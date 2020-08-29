#pragma once

typedef int DataType;
typedef struct ListNode
{
	DataType data;//数据域
	struct ListNode* pre;//前驱指针域
	struct ListNode* next;//后继指针域
}ListNode;


// 创建返回链表的头结点.
ListNode* ListCreate();
// 双向链表销毁
void ListDestory(ListNode* phead);
// 双向链表打印
void ListPrint(ListNode* phead);
// 双向链表尾插
void ListPushBack(ListNode* phead, DataType x);
// 双向链表尾删
void ListPopBack(ListNode* phead);
// 双向链表头插
void ListPushFront(ListNode* phead, DataType x);
// 双向链表头删
void ListPopFront(ListNode* phead);
// 双向链表查找
ListNode* ListFind(ListNode* phead, DataType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, DataType x);
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);