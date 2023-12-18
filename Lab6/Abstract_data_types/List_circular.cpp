#include "List_circular.h"

Node_c::Node_c() {
	next = NULL;
}

Node_c::~Node_c() {

}

void Node_c::insert(Pos index, TypeItem x)
{
	list_c temp, current = this;
	Pos i = Pos(0);
	while (current->next && i < index) {
		current = current->next;
		i++;
	}
	if (i == index) {
		temp = new Node_c;
		if (index == 0 && !is_empty()) {
			do {
				current = current->next;
			} while (current->next != next);
			current->next = temp;
			current = this;
		}
		temp->next = current->next;
		current->next = temp;
		temp->item = x;
		current->next = temp;
		if (!temp->next) temp->next = next;
	}
}

void Node_c::remove(Pos index)
{
	list_c temp, current = this;
	Pos i = Pos(0);
	if (is_empty()) {
		cout << "Заданной позиции не существует\n";
		return;
	}
	while (current->next && i < index) {
		current = current->next;
		i++;
	}
	if (current->next && i == index) {
		temp = current->next;		
		if (index == 0) {
			do {
				current = current->next;
			} while (current->next != next);
			current->next = temp->next;
			current = this;
		}
		current->next = temp->next;
		temp->next = NULL;
		delete temp;
		return;
	}
	cout << "Заданной позиции не существует\n";
}

Pos Node_c::find(TypeItem x)
{
	list_c current = next;
	Pos i = Pos(0);
	if (!next) return -1;
	else {
		do {
			if (current->item == x) return (i);
			current = current->next;
			i++;
		} while (current != next);
	}
	return -1;
}

TypeItem Node_c::retriеve(Pos index)
{
	list_c current = next;
	Pos i = Pos(0);
	if (getLength() <= index) return -1;
	if (!next) return -1;
	else {
		while (current && i < index) {
			current = current->next;
			i++;
		}
		if (i == index) return current->item;
	}
}

bool Node_c::is_empty() {
	if (next) return false;
	return true;
}

int Node_c::getLength() {
	list_c current = next;
	Pos i = Pos(0);
	if (!next) return i;
	else {
		do {
			current = current->next;
			i++;
		} while (current != next);
	}
	return i;
}