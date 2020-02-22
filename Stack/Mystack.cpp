// stack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;


#define STACK_COUNTER 0 


//指针栈
void** sarray;
int top = -1;			//栈顶
int addSize = 10;		//每次扩增10
int stacksize = 0;		//记录栈的大小


void** initStack(int size)
{
	stacksize = size;
	int i = 0;
	sarray = (void**)malloc(sizeof(void*) * size);
	for (i; i < size; i++)
	{
		sarray[i] = { 0 };
	}
	return sarray;
}




void grow()
{
	stacksize += addSize;
	int i = 0;
	void ** temp = (void**)malloc(sizeof(void*) * stacksize);

	for (i; i < stacksize - 10; i++)
	{
		*(temp + i) = *(sarray + i);
	}
	free(sarray);
	sarray = temp;
}


void push(void* object)
{
	if (top < stacksize)
	{
		top++;
		*(sarray + top) = object;
	}
	else
	{
		grow();
		push(object);
	}
}


void* pop()
{
	void* val = *(sarray + top);
	top--;
	return val;
}


int size()
{
	return stacksize;
}


int isEmpty()
{
	return stacksize == 0;
}

void* stackTop()
{
	return sarray[top];
}
