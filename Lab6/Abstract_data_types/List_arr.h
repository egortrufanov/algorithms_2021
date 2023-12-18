#pragma once
#include <iostream>

using namespace std;

typedef int TypeItem;
typedef int Pos;
constexpr auto max_list = 100;

class List 
{
public:
	List();
	~List();
	void insert(int index, TypeItem NewItem);
	void remove(int index);
	Pos find(TypeItem x);
	TypeItem retriåve(int index);
	bool is_empty();
	int getLength();
private:
	TypeItem items[max_list];
	int next;
};
