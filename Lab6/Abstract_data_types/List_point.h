#pragma once
#include <iostream>

using namespace std;

typedef int TypeItem;
typedef int Pos;

class Node
{
public:
	Node();
	~Node();
	void insert(Pos index, TypeItem x);
	void remove(Pos index);
	Pos find(TypeItem x);
	TypeItem retri�ve(Pos index);
	bool is_empty();
	int getLength();
private:
	TypeItem item;
	Node *next;
};
typedef Node *list;



