#pragma once
#include <iostream>

using namespace std;

typedef int TypeItem;

class Stack_p{
public:
	Stack_p();
	~Stack_p();
	bool is_empty() const;
	void push(TypeItem newItem);
	void pop();
	void pop(TypeItem& stackTop);
	TypeItem get_top() const;
private:
	struct StackNode
	{
		TypeItem item;
		StackNode *next;
	};
	StackNode *top;
};