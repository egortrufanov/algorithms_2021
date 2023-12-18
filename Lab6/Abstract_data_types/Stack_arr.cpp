#include "Stack_arr.h"

Stack_arr::Stack_arr() {
	top = 0;
}

Stack_arr::~Stack_arr() {}

void Stack_arr::pop() {
	if (top == 0) cout << "Стек пуст\n";
	else --top;
}

void Stack_arr::push(TypeItem newItem)
{
	if (top >= max_size) cout << "Стек полон\n";
	else stack[++top] = newItem;
}

TypeItem Stack_arr::get_top()
{
	if (top == 0) {
		cout << "Стек пуст\n";
		return numeric_limits<int>::max();
	}
	else return stack[top];
}

bool Stack_arr::is_empty() {
	return top == 0; 
}