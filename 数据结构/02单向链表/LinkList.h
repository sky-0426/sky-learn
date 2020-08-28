#pragma once
typedef int DateType;
//������
typedef struct ListNode
{
	DateType date;
	struct ListNode* next;
}ListNode;

// ��̬����һ���ڵ�
ListNode* BuyListNode(DateType x);
// �������ӡ
void ListPrint(ListNode* plist);
// ������β��
void ListPushBack(ListNode** pplist, DateType x);
// �������ͷ��
void ListPushFront(ListNode** pplist, DateType x);
// �������βɾ
void ListPopBack(ListNode** pplist);
// ������ͷɾ
void ListPopFront(ListNode** pplist);
// ���������
ListNode* ListFind(ListNode* plist, DateType x);
// ��������posλ��֮�����x
void ListInsertAfter(ListNode* pos, DateType x);
// ������ɾ��posλ��֮���ֵ
void ListEraseAfter(ListNode* pos);
//�����������
void ListDestory(ListNode** pplist);