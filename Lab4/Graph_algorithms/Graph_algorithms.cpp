#include <iostream>
#include <string>
#include "Graph.h"

int main() {
	setlocale(LC_ALL, "Russian");
	Graph g({
		 {0,17,6,11,0,0,0,0},
		 {17,0,0,8,0,0,0,0},
		 {6,0,0,25,19,0,0,0},
		 {11,8,25,0,0,0,2,0},
		 {0,0,19,0,0,9,0,0},
		 {0,0,0,0,9,0,14,0},
		 {0,0,0,2,0,14,0,21},
		 {0,0,0,0,0,0,21,0},
		});
	cout << "Номер вершины, для которой требуется найти пути до остальных вершин: ";
	int x;
	cin >> x;
	g.depth(x);
	g.width(x);
	g.Dijkstras(x);
	g.Kruskals();
}