#pragma once
#include <iostream>
#include "List_point.h"

using namespace std;

typedef int TypeItem;
typedef int Pos;

class Node_d 
{
public:
	Node_d();
	~Node_d();
	void insert(Pos index, TypeItem x);
	void remove(Pos index);
	Pos find(TypeItem x);
	TypeItem retriåve(Pos index);
	bool is_empty();
	int getLength();

	void getReversed();
private:
	TypeItem item;
	Node_d *next;
	Node_d *prev;
};
typedef Node_d *list_d;