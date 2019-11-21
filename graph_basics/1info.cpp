#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// There are two ways to represent a graph: Adjacency lists and Adjacency matrices
	vector<vector<int>> adj_list;
	vector<vector<bool>> adj_matrix;
	// In both of these, vertices are labelled with integers.
	// For a graph with n vertices, the vertex labels are 0,1,2,...,n-1

	// Each of these has their own benefits
	//
	// In the adjacency matrix model, we can very quickly handle queries asking:
	// 	"Are vertices u and v adjacent in the graph"?
	// This can be done by checking adj_matrix[u][v]
	//
	// For a graph with n vertices and m edges,
	// the adjacency matrix model takes O(n^2) space
	//
	// In the adjacency list model,
	// 	we can iterate through the neighbours of a vertex quickly
	// e.g.
	// for (int u : adj_list[v])
	// 	// do something with the adjacent vertex u
	//
	// For a graph with n vertices and m edges,
	// the adjacency list model takes O(n+m) space (better when m<n^2)
}
