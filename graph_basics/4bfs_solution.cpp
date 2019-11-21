#include <iostream>
#include <vector>

using namespace std;

// We're going to implement the same functions as last time,
// but this time let's improve the runtime to O(n).
// How do we do this?
// Let's use breadth-first search!

// Given an adjacency list, two vertices v and u,
// and a distance d
// determine if v and u are at most d edges away from each other,
// using at most O(n) time and space
bool within_d(const vector<vector<int>> &adj_list, int u, int v, int d)
{
	// TODO complete this function.
	// Tip: Use a queue and a distance array

	// Solution: BFS
	// Look at every node in order of distance from u
	
	// array of distances from u
	// -1 means unseen (infinite distance)
	// a vertex can be 'seen' from any visited vertex
	vector<int> distance(adj_list.size(),-1);
	distance[u] = 0;

	queue<int> todo; // vertices we need to look at
	todo.push(u);

	// while we still have vertices to look at
	while (!todo.empty())
	{
		// choose the first (closest) one to look at
		int cur = todo.front(); todo.pop();

		// for every adjacent node to cur
		for (int next : adj_list[cur])
		{
			// if the node hasn't been seen before
			if (distance[next] == -1)
			{
				// visit the adjacent node
				todo.push(next);
				distance[next] = distance[cur] + 1;
			}
		}
		
		// is the distance to v small enough?
		return distance[v] <= d;
	}
}

void check_within_d(const vector<vector<int>> &adj, int u, int v, int d)
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
	return false; // stub
}

void check_connected(const vector<vector<int>> &adj, int u, int v)
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
