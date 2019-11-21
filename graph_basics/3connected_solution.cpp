#include <iostream>
#include <vector>

// Given an adjacency list, two vertices v and u,
// and a distance d
// determine if v and u are at most d edges away from each other
bool within_d(const vector<vector<int>> &adj_list, int u, int v, int d)
{
	// TODO complete this function. Don't worry about runtime.
	// Tip: Use recursion, and do something similar to close_by.

	// Solution: Use recursion to essentially create d for loops,
	// 	similarly to close_by
	
	// found it!
	if (u == v)
		return true;

	// base case: d==0 (no more edges)
	if (d == 0)
		return false;

	// recurse on adjacent edges to see if any of the sub-searches find v
	bool res = false;
	for (int w : adj_list[u])
		res = res || within_d(adj_list,w,v,d-1);
	return res;
}

void check_within_d(const vector<vector<int>> &adj, u, v, d)
{
	cout << "Are vertices " << u << " and " << v
		<< " at most " << d << " edges apart? "
		<< within_d(adj,u,v,d)
		<< endl;
}

// Given an adjacency list and two vertices v and u,
// determine if v and u are connected
bool connected(const vector<vector<int>> &adj_list, int u, int v)
{
	// TODO complete this function.
	// Hint: This should only take one line. Use within_d!
	// Solution: If two vertices are connected, the distance between them is at most n
	return within_d(adj_list,u,v,adj_list.size());
}

void check_connected(const vector<vector<int>> &adj, u, v)
{
	cout << "Are vertices " << u << " and " << v << " connected? "
		<< connected(adj,u,v) << endl;
}

int main()
{
	// Create a graph:
	//     5--4  0--8  9--10
	//    /|  |  |\
	//   / |  |  | \
	//  7--6  3--2--1
	vector<vector<int>> adj(11);
	adj[0] = {1,2,8};
	adj[1] = {0,2};
	adj[2] = {0,1,3};
	adj[3] = {2,4};
	adj[4] = {3,5};
	adj[5] = {4,6,7};
	adj[6] = {5,7};
	adj[7] = {5,6};
	adj[8] = {0};
	adj[9] = {10};
	adj[10] = {9};

	check_within_d(adj,0,5,3);
	check_within_d(adj,0,5,4);
	check_within_d(adj,0,5,5);
	check_within_d(adj,8,4,4);
	check_within_d(adj,8,4,3);
	check_within_d(adj,7,1,5);

	check_connected(adj,0,7);
	check_connected(adj,1,8);
	check_connected(adj,9,10);
	check_connected(adj,9,1);
	check_connected(adj,2,10);
}
