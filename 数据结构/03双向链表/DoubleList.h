#pragma once

typedef int DataType;
typedef struct ListNode
{
	DataType data;//������
	struct ListNode* pre;//ǰ��ָ����
	struct ListNode* next;//���ָ����
}ListNode;


// �������������ͷ���.
ListNode* ListCreate();
// ˫����������
void ListDestory(ListNode* phead);
// ˫�������ӡ
void ListPrint(ListNode* phead);
// ˫������β��
void ListPushBack(ListNode* phead, DataType x);
// ˫������βɾ
void ListPopBack(ListNode* phead);
// ˫������ͷ��
void ListPushFront(ListNode* phead, DataType x);
// ˫������ͷɾ
void ListPopFront(ListNode* phead);
// ˫���������
ListNode* ListFind(ListNode* phead, DataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, DataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);