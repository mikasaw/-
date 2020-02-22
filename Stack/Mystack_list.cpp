#include<iostream>

using namespace std;

#define STACK_IS_EMPTY 1

//使用链表实现的栈
struct elem {
	void* val;
	struct elem* next;
};

struct MyStack {
	int count;
	elem * head;
};



MyStack* Stack_init()
{
	MyStack* stack = new MyStack;
	//stack = (MyStack*)malloc(sizeof(MyStack));
	stack->count = 0;
	stack->head = NULL;
	return stack;
}

int Stack_empty(MyStack stack)
{
	if (stack.count == 0)
		return  STACK_IS_EMPTY;
	else
		return 0;
}

int Stack_size(MyStack stack)
{
	return stack.count;
}



void Stack_push(MyStack stack, void* val)
{
	
	auto t = (elem*)malloc(sizeof(elem));
	t->val = val;
	t->next = stack.head;
	stack.head = t;
	stack.count++;
}


void* Stack_pop(MyStack stack)
{
	if (stack.count == 0)
		return 0;

	auto t = stack.head;      //使用C++11的自动推断功能
	stack.head = t->next;
	stack.count--;
	auto val = t->val;
	free(t);
	return val;

}

void Stack_print(MyStack stack)
{
	if (stack.count == 0)
		return ;
	auto t = (elem*)malloc(sizeof(elem));
	t = stack.head;
	while ( t != NULL)
	{
		cout << t->val << endl;
		t = t->next;
	}

}
