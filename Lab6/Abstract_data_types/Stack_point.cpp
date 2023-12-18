#include "Stack_point.h"

Stack_p::Stack_p() : top(NULL) {}

Stack_p::~Stack_p()
{
	while (!is_empty()) pop();
}

void Stack_p::pop() {
	if (is_empty()) cout << "Стек пуст\n";
	else
	{
		StackNode *temp = top;
		top = top->next;
		temp->next = NULL;
		delete temp;
	}
}

void Stack_p::pop(TypeItem &stackTop) {
	if (is_empty()) cout << "Стек пуст\n";
	else
	{
		stackTop = top->item;
		StackNode *temp = top;
		top = top->next;
		temp->next = NULL;
		delete temp;
	}
}

void Stack_p::push(TypeItem newItem) {
	StackNode *temp = new StackNode;
	temp->item = newItem;
	temp->next = top;
	top = temp;
}

bool Stack_p::is_empty() const {
	return top == NULL;
}

TypeItem Stack_p::get_top() const {
	if (is_empty()) {
		cout << "Стек пуст\n";
		return numeric_limits<int>::max();
	}
	else return top->item;
}