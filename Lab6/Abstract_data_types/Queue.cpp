#include "Queue.h"

Queue::Queue()
{
	front = 0;
	rear = -1;
	count = 0;
}

Queue::~Queue() {}

void Queue::en_queue(TypeItem newItem)
{
	if (count == max_queue)
		cout << "Очередь полна\n";
	else {
		rear = (rear + 1) % max_queue;
		items[rear] = newItem;
		++count;
	}
}

void Queue::de_queue()
{
	if (is_empty())
		cout << "Очередь пуста\n";
	else {
		front = (front + 1) % max_queue;
		--count;
	}
}

TypeItem Queue::get_front()
{
	if (is_empty()) {
		cout << "Очередь пуста\n";
		return numeric_limits<int>::max();
	}
	else
		return items[front];
}

bool Queue::is_empty()
{
	return count == 0;
}