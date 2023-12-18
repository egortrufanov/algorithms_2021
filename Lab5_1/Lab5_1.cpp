#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

int Priority(char c) {
	switch (c) {
	case '+':case '-':
		return 1;
	case '*':case '/':
		return 2;
	}
	return 100;
}

int LastOperation(char Expr[], int first, int last) {
	int MinPrt, i, k, prt;
	k = 0;
	MinPrt = 100;
	for (i = first; i <= last; i++) {
		prt = Priority(Expr[i]);
		if (prt <= MinPrt) {
			MinPrt = prt;
			k = i;
		}
	}
	return k;
}

struct Node {
	char data;
	Node* left, * right;
};
typedef Node* PNode;

PNode NumberNode(char c) {
	PNode Tree = new Node;
	Tree->data = c;
	Tree->left = NULL;
	Tree->right = NULL;
	return Tree;
}

PNode MakeTree(char Expr[], int first, int last) {
	PNode Tree;
	int k;
	if (first == last)
		return NumberNode(Expr[first]);
	k = LastOperation(Expr, first, last);
	Tree = new Node;
	Tree->data = Expr[k];
	Tree->left = MakeTree(Expr, first, k - 1);
	Tree->right = MakeTree(Expr, k + 1, last);
	return Tree;
}

int CalcTree(PNode Tree) {
	int num1, num2;
	if (!Tree->left) return Tree->data - '0';
	num1 = CalcTree(Tree->left);
	num2 = CalcTree(Tree->right);
	switch (Tree->data) {
	case'+':return num1 + num2;
	case'-':return num1 - num2;
	case'*':return num1 * num2;
	case'/':return num1 / num2;
	}
	return 32767;
}

int main() {
	setlocale(LC_ALL, "Russian");
	char s[80];
	PNode Tree;
	cout << "Напишите выражение: ";
	cin >> s;
	Tree = MakeTree(s, 0, strlen(s) - 1);
	cout << CalcTree(Tree);
}