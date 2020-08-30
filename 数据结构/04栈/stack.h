#pragma once
#include <stdio.h>
#include <stdlib.h>

// 支持动态增长的栈
typedef int DataType;
typedef struct Stack
{
	DataType* arr;
	int top; //栈顶指针,初始top为0，指向栈顶的下一个位置
	int capacity; //容量
}Stack;
// 初始化栈
void StackInit(Stack* ps)
{
	ps->top = 0;
	ps->capacity = 2;
	ps->arr = (DataType*)malloc(sizeof(DataType)*ps->capacity);

}
// 入栈
void StackPush(Stack* ps, DataType data)
{
	//判断栈是否已满
	if (ps->top == ps->capacity)
	{
		//将栈的容量加倍
		ps->capacity = ps->capacity * 2;
		//申请新的空间并将之前的数据复制过去
		ps->arr = (DataType*)realloc(ps->arr,sizeof(DataType)*ps->capacity);
	}
	//将数据入栈
	ps->arr[ps->top] = data;
	ps->top++;
}
// 出栈
void StackPop(Stack* ps)
{
	//判端栈是否为空
	if (ps->top == 0)
	{
		return;
	}
	//栈顶指针减一
	ps->top--;
}
// 获取栈顶元素
DataType StackTop(Stack* ps)
{
	//若栈为空，直接return退出
	if (ps->top == 0)
	{
		return;
	}
	//栈不为空，返回栈顶数据元素
	return ps->arr[ps->top-1];
}
// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	return ps->top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
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
// 销毁栈
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
