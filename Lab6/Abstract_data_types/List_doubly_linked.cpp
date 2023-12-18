#include "List_doubly_linked.h"

Node_d::Node_d() {
	next = NULL;
	prev = NULL;
}

Node_d::~Node_d() {
	if (next)
		delete next;
}
void Node_d::insert(Pos index, TypeItem x)
{
	list_d temp, current = this;
	Pos i = Pos(0);
	while (current->next && i < index) {
		current = current->next;
		i++;
	}
	if (i == index) {
		temp = new Node_d;
		if (current->next) current->next->prev = temp;
		temp->next = current->next;
		current->next = temp;
		temp->prev = current;
		temp->item = x;
		return;
	}
}

void Node_d::remove(Pos index)
{
	list_d temp, current = this;
	Pos i = Pos(0);
	//останавливаемся перед нужным индексом, чтобы пропустить удаляемый
	while (current->next && i < index) {
		current = current->next;
		i++;
	}
	if (current->next && i == index) {
		temp = current->next;			
		current->next = temp->next;
		if (temp->next) temp->next->prev = current;
		temp->next = NULL;
		delete temp;				
		return;
	}
	cout << "Заданной позиции не существует\n";
}

Pos Node_d::find(TypeItem x)
{
	list_d current = next;
	Pos i = Pos(0);
	if (!next) return -1;
	else {
		while (current) {
			if (current->item == x) return (i);
			current = current->next;
			i++;
		}
	}
}

TypeItem Node_d::retriеve(Pos index)
{
	list_d current = next;
	Pos i = Pos(0);
	if (!next) return -1;
	else {
		while (current && i < index) {
			current = current->next;
			i++;
		}
		if (i == index) return current->item;
	}
}

bool Node_d::is_empty() {
	if (next) return false;
	return true;
}

int Node_d::getLength() {
	list_d current = next;
	Pos i = Pos(0);
	while (current) {
		current = current->next;
		i++;
	}
	return i;
}

void Node_d::getReversed() {
	if (!next) {
		return;
	}
	list_d current = next;
	while (current->next != NULL)
		current = current->next;
	do {
		cout << current->item << " ";
		current = current->prev;
	} while (current != this);
}