#include "List_arr.h"

List::List() {
	next = 0;
}

List::~List() {}

void List::insert(int index, TypeItem NewItem)
{
	if (next >= 100) cout << "Список полон";
	else if (index > next || index < 0)
		cout << "Такой позиции нет";
	else {
		for (auto i = next; i > index; i--)
			items[i] = items[i - 1];
		next++;
		items[index] = NewItem;
	}
}

void List::remove(int index)
{
	if (index >= next || index < 0)
		cout << "Заданной позиции не существует\n";
	else {
		next = next - 1;
		for (auto i = index; i < next; i++)
			items[i] = items[i + 1];
	}
}

Pos List::find(TypeItem x)
{
	for (auto i = 0; i < next; i++)
		if (items[i] == x) return(i);
	return -1;
}

TypeItem List::retriеve(int index) {
	return items[index];
}

bool List::is_empty() {
	if (next == 0) return true;
	return false;
}

int List::getLength() {
	return next;
}