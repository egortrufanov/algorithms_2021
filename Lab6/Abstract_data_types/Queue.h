#pragma once
#include <iostream>

using namespace std;

typedef int TypeItem;

constexpr auto max_queue = 100;

class Queue {
public:
	Queue();
	~Queue();
	bool is_empty();
	void en_queue(TypeItem newItem);
	void de_queue();
	TypeItem get_front();
private:
	TypeItem items[max_queue];
	int front;
	int rear; 
	int count;
};