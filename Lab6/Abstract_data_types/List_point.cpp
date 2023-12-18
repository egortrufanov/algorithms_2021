#include "List_point.h"

Node::Node() {
	next = NULL;
}

Node::~Node() {
	if (next)
		delete next;
}

void Node::insert(Pos index, TypeItem x)
{
	list temp, current = this;
	Pos i = Pos(0);
	while (current->next && i < index) {
		current = current->next;
		i++;
	}
	if (i == index) {
		temp = new Node;
		temp->next = current->next;
		temp->item = x;
		current->next = temp;
		return;
	}
}

void Node::remove(Pos index)
{
	list temp, current = this;
	Pos i = Pos(0);
	//останавливаемся перед нужным индексом, чтобы пропустить удаляемый
	while (current->next && i < index) {
		current = current->next;	
		i++;					
	}
	if (current->next && i == index) {
		temp = current->next;		
		current->next = temp->next;
		temp->next = NULL;
		delete temp;
		return;
	}
	cout << "Заданной позиции не существует\n";
}

Pos Node::find(TypeItem x)
{
	list current = next;
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

TypeItem Node::retriеve(Pos index)
{
	list current = next;
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

bool Node::is_empty() {
	if (next) return false;
	return true;
}

int Node::getLength() {
	list current = next;
	Pos i = Pos(0);
	while (current) {
		current = current->next;
		i++;
	}
	return i;
}
