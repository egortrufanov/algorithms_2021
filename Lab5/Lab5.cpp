#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node {
	char info;
	struct node* llink;
	struct node* rlink;
};
void vtree(struct node** t) {
	char c;
	scanf_s("%c", &c);
	if (c != '.') {
		*t = (struct node*)malloc(sizeof(struct node));
		(*t)->info = c;
		vtree(&((*t)->llink));
		vtree(&((*t)->rlink));
	}
	else
		*t = NULL;
}

void reverse(struct node* t) {
	if (t != NULL) {
		reverse(t->llink);
		printf("%c ", t->info);
		reverse(t->rlink);
	}
}
void straight(struct node* t) {
	if (t != NULL) {
		printf("%c ", t->info);
		straight(t->llink);
		straight(t->rlink);
	}
}
void end(struct node* t) {
	if (t != NULL) {
		end(t->llink);
		end(t->rlink);
		printf("%c ", t->info);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	struct node* root;
	vtree(&root);
	cout << "Обход дерева в прямом порядке: ";
	straight(root);
	cout << endl << "Обход дерева в обратном порядке: ";
	reverse(root);
	cout << endl << "Обход дерева в концевом порядке: ";
	end(root);
	return 0;
}