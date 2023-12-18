#pragma once
#include <iostream>

using namespace std;

typedef int TypeItem;

constexpr auto max_size = 100;

class Stack_arr {
public:
	Stack_arr();
	~Stack_arr();
	bool is_empty();
	void push(TypeItem newItem);
	void pop();
	TypeItem get_top();
private:
	TypeItem stack[max_size];
	int top;
};