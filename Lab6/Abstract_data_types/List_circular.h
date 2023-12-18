#pragma once
#include <iostream>

using namespace std;

typedef int TypeItem;
typedef int Pos;

class Node_c
{
public:
	Node_c();
	~Node_c();
	void insert(Pos index, TypeItem x);
	void remove(Pos index);
	Pos find(TypeItem x);
	TypeItem retriåve(Pos index);
	bool is_empty();
	int getLength();
private:
	TypeItem item;
	Node_c *next; 
};
typedef Node_c *list_c;