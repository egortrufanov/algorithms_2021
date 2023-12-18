#pragma once
#include <vector>

using namespace std;

class Graph
{
public:
	Graph(vector<vector<int>> w);
	~Graph() {}

	void depth(int x);
	void width(int x);
	void Dijkstras(int x);
	void Kruskals();

private:
	int Depth(int from, int to, vector<int> &visited, vector<int> &path, vector<vector<int>> t = {});
	vector<vector<int>> w;
};