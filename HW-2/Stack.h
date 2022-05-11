#ifndef __STACK__
#define __STACK__
#include "StackItem.h"

class Stack {
public:
	Stack();
	void push(StackItem*);
	StackItem* pop();
	StackItem* top();
	bool isEmpty();
	~Stack();

private:
	StackItem* head;
};

#endif