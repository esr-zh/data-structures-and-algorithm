#include "Stack.h"
#include "StackItem.h"

Stack::Stack(){
	head = NULL;
}

void Stack::push(StackItem* item) {
	StackItem* itm = new StackItem(*item);

	if (head == NULL)
	{
		head = itm; //stack item pushed
	}
	else
	{
		itm->next = head;
		head = itm;
	}
}

StackItem* Stack::pop() {
	StackItem* temp = head;
	if (isEmpty()) // if stack underflow
	{	
		return(temp);
	}
	else
	{ 
		head = head->next;
	}
	return temp;
}

StackItem* Stack::top(){
	if (!isEmpty()) {
		return head;
	}
	else
	{
		return 0;
	}
}

bool Stack::isEmpty() {
	return(head == NULL);
}

Stack::~Stack() {
	StackItem* dnode = head;
	while (dnode != 0) {
		head = head->next;
		delete dnode;
		dnode = head;
	}
}