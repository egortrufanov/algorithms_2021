#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include "Graph.h"

void Matrix_out(vector<vector<int>> w) {
	cout << "      0  1  2  3  4  5  6  7\n\n";
	for (int i = 0; i < w.size(); ++i) {
		cout << i << "  [  ";
		for (auto j : w[i]) {
			cout << j << " ";
			if (j < 8) cout << " ";
		}
		cout << "]\n";
	}
}

Graph::Graph(vector<vector<int>> w)
{
	this->w = w;
	cout << "Заданная матрица смежности графа" << endl;
	Matrix_out(w);
}

void Graph::depth(int x) {
	cout << "\nАлгоритм поиска в глубину:\n";
	cout << "Пути от вершины \"" << x << "\"" << endl;
	for (auto i : { 0,1,2,3,4,5,6,7}) {
		if (i == x) continue;
		vector<int> visited(w.size(), false), path;
		int path_size = Depth(x, i, visited, path);
		reverse(path.begin(), path.end());
		for (int j = 0; j < path.size() - 1; ++j) {
			cout << path[j] << " -> ";
		}
		cout << path.back();
		cout << " (" << path_size << ")\n";
	}
}

int Graph::Depth(int from, int to, vector<int> &visited, vector<int> &path, vector<vector<int>> t) {
	if (t.empty()) {
		t = w;
	}
	visited[from] = true;
	if (from == to) {
		path.push_back(to);
		return 0;
	}
	for (int i = 0; i < t.size(); ++i) {
		if (!visited[i] && t[from][i] != 0) {
			int path_size = Depth(i, to, visited, path, t);
			if (path_size < 0)
				continue;
			path.push_back(from);
			return path_size + t[from][i];
		}
	}
	return -1;
}

void Graph::width(int x) {
	cout << "\nАлгоритм поиска в ширину:\n";
	cout << "Кратчайшие пути от вершины \"" << x << "\"" << endl;
	for (auto i : { 0,1,2,3,4,5,6,7}) {
		if (i == x) continue;
		map<int, int> path;
		vector<bool> used(9);
		vector<int> lenght(9, -1);
		queue<int> q;
		q.push(x);
		used[x] = true;
		lenght[x] = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			vector<pair<int, int>> vertex;
			for (int j = 0; j < w.size(); ++j)
				if (w[cur][j] != 0)
					vertex.push_back({ j,w[cur][j] });

			for (pair<int, int> neighbor : vertex) {
				if (lenght[neighbor.first] > neighbor.second + lenght[cur] || lenght[neighbor.first] == -1) {
					lenght[neighbor.first] = neighbor.second + lenght[cur];
					path[neighbor.first] = cur;
				}
				if (!used[neighbor.first]) {
					q.push(neighbor.first);
					used[neighbor.first] = true;
				}
			}
		}
		int temp = i;
		vector<int> t;
		do {
			temp = path[temp];
			t.push_back(temp);
		} while (temp != x);
		reverse(t.begin(), t.end());
		for (auto j : t) {
			cout << j << " -> ";
		}
		cout << i;
		cout << " (" << lenght[i] << ")\n";
	}
}


void Graph::Kruskals() {
	cout << "\nАлгоритм Крускала:\n";
	int size = 9;
	vector<pair<int, int>> e, out;
	for (int i = 0; i < w.size(); ++i) {
		for (int j = i + 1; j < w.size(); ++j) {
			if (w[i][j] != 0) {
				e.push_back({ i,j });
			}
		}
	}
	const vector<vector<int>> temp = w;
	bool q = true;
	while (q) {
		q = false;
		for (int i = 0; i < size - 1; ++i) {
			if (temp[e[i].first][e[i].second] > temp[e[i + 1].first][e[i + 1].second]) {
				swap(e[i], e[i + 1]);
				q = true;
			}
		}
	}
	vector<vector<int>> t(8, vector<int>(8, 0));
	for (const auto &i : e) {
		vector<int> visited(w.size(), false), path;
		int q = Depth(i.first, i.second, visited, path, t);
		if (q == -1) {
			out.push_back(i);
			t[i.first][i.second] = w[i.first][i.second];
			t[i.second][i.first] = w[i.second][i.first];
		}
	}
	cout << "Минимальный остов графа (дуги):" << endl;
	for (int i = 0; i < out.size(); ++i)
		cout << "{" << out[i].first << " " << out[i].second << "}";
	cout << "\n\nМинимальный остов графа (матрица смежности):" << endl;
	Matrix_out(t);
}


void Graph::Dijkstras(int x) {
	cout << "\nАлгоритм Дейкстры:\n";
	vector<int> a(w.size(),0), c(w.size(), x), b;
	a[x] = 1;
	for (int i = 0; i < a.size(); ++i) {
		if (w[x][i] == 0 && i != x)
			b.push_back(-1);
		else b.push_back(w[x][i]);
	}
	while (find(a.begin(), a.end(), 0) != a.end()) {
		int min = -1, min_id;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] == 0 && b[i] != -1 && (b[i] < min || min == -1)) {
				min = b[i];
				min_id = i;
			}
		}
		a[min_id] = 1;
		for (int i = 0; i < a.size(); ++i) {
			if (w[min_id][i] != 0 && (w[min_id][i] + min < b[i] || b[i] == -1)) {
				b[i] = w[min_id][i] + min;
				c[i] = min_id;
			}
		}
	}
	cout << "Кратчайшие пути от вершины \"" << x << "\"" << endl;
	for (auto temp : { 0,1,2,3,4,5,6,7}) {
		vector<int> t;
		if (temp == x) continue;
		int k = temp;
		do {
			t.push_back(temp);
			temp = c[temp];
		} while (temp != x);
		cout << x;
		reverse(t.begin(), t.end());
		for (const auto &i : t) {
			cout << " -> " << i;
		}
		cout << " (" << b[k] << ")" << endl;
	}
}
