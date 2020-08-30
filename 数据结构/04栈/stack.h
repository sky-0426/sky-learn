#pragma once
#include <stdio.h>
#include <stdlib.h>

// ֧�ֶ�̬������ջ
typedef int DataType;
typedef struct Stack
{
	DataType* arr;
	int top; //ջ��ָ��,��ʼtopΪ0��ָ��ջ������һ��λ��
	int capacity; //����
}Stack;
// ��ʼ��ջ
void StackInit(Stack* ps)
{
	ps->top = 0;
	ps->capacity = 2;
	ps->arr = (DataType*)malloc(sizeof(DataType)*ps->capacity);

}
// ��ջ
void StackPush(Stack* ps, DataType data)
{
	//�ж�ջ�Ƿ�����
	if (ps->top == ps->capacity)
	{
		//��ջ�������ӱ�
		ps->capacity = ps->capacity * 2;
		//�����µĿռ䲢��֮ǰ�����ݸ��ƹ�ȥ
		ps->arr = (DataType*)realloc(ps->arr,sizeof(DataType)*ps->capacity);
	}
	//��������ջ
	ps->arr[ps->top] = data;
	ps->top++;
}
// ��ջ
void StackPop(Stack* ps)
{
	//�ж�ջ�Ƿ�Ϊ��
	if (ps->top == 0)
	{
		return;
	}
	//ջ��ָ���һ
	ps->top--;
}
// ��ȡջ��Ԫ��
DataType StackTop(Stack* ps)
{
	//��ջΪ�գ�ֱ��return�˳�
	if (ps->top == 0)
	{
		return;
	}
	//ջ��Ϊ�գ�����ջ������Ԫ��
	return ps->arr[ps->top-1];
}
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	return ps->top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	if (ps->top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
// ����ջ
void StackDestroy(Stack* ps)
{
	free(ps->arr);
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}

void teststack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4); 

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
}
