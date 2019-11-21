#include <iostream>
#include <vector>

// Given an adjacency list and a vertex v,
// find the number of vertices adjacent to v
int adjacent_count(const vector<vector<int>> &adj_list, int v)
{
	// TODO complete this function
	// Solution: the adjacency list is a list of elements adjacent to v,
	// so return it's size
	return adj_list[v].size();
}

// Given and adjacency list and two vertices v and u,
// determine if v and u are at most two edges away from each other
bool close_by(const vector<vector<int>> &adj_list, int u, int v)
{
	// TODO complete this function
	// Tip: No need to use graph traversals

	return false;
}

void check_close_by(const vector<vector<int>> adj, int u, int v)
{
	cout << "Question: Are vertices " << u << " and " << v
		<< " at most two edges away from each other? " << close_by(adj,u,v) << endl;
}

int main()
{
	// Create a graph:
	//   4  0
	//   |  |\
	//   |  | \
	//   3--2--1
	vector<vector<int>> adj_1(5);
	adj[0] = {1,2};
	adj[1] = {0,2};
	adj[2] = {0,1,3};
	adj[3] = {2,4};
	adj[4] = {3};

	cout << "In graph 1, the number of vertices adjacent to vertex 2 is "
		<< adjacent_count(adj_1, 2) << endl;

	for (int u = 0; u < 5; ++u)
		for (int v = u + 1; v < 5; ++v)
			check_close_by(adj_1,u,v);
}
