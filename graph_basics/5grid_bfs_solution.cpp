#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Graphs aren't always represented as adjacency lists or adjacency matrices
// Special classes of graphs can be represented in other ways
// As an example, consider a maze:
// #.#.###.a
// #...##..#
// #.#....##
// #b#.#..##
// Can we find a (shortest) path from a to b that does not go outside the maze or through tiles labelled #?
// We can do this with bfs on the graph that connects the usable tiles with edges in the 4 canonical directions.
// But we shouldn't construct the graph in another form if we don't need to. Why don't we just leave it as a grid?


// Use this struct to store positions in the grid
struct position
{
	int x, y;
	position() : x(-1), y(-1) {}
	position(int x, int y) : x(x), y(y) {}
};

// Given a grid of chars, and two characters that each appear once on the grid
// find the distance between the points corresponding to the characters
// using linear time and space
bool find_distance(const vector<vector<char>> &grid, char a, char b)
{
	position a_loc, b_loc;
	// Find where a and b are
	for (int i = 0; i < grid.size(); ++i)
		for (int j = 0; j < grid[i].size(); ++j)
		{
			if (grid[i][j] == a)
				a_loc = position(i,j);
			if (grid[i][j] == b)
				b_loc = position(i,j);
		}

	// TODO complete this function.
	// Tip: Start from your solution to BFS within_d from the previous part

	// Solution: BFS
	
	// grid of distances from a
	// -1 means unseen (infinite distance)
	// a vertex can be 'seen' from any visited vertex
	vector<vector<int>> distance(grid.size(),vector<int>(grid[0].size(),-1));
	distance[a_loc.x][a_loc.y] = 0;

	queue<position> todo; // grid locations we need to look at
	todo.push(a_loc);

	// while we still have grid locations to look at
	while (!todo.empty())
	{
		// choose the first (closest) one to look at
		position cur = todo.front(); todo.pop();

		// what are the adjacent nodes in a grid?
		// They're the
		vector<position> adj;
		if (cur.x - 1 >= 0)
			adj.push_back(position(cur.x-1,cur.y));
		if (cur.y - 1 >= 0)
			adj.push_back(position(cur.x,cur.y-1));
		if (cur.x + 1 < grid.size())
			adj.push_back(position(cur.x+1,cur.y));
		if (cur.y + 1 < grid[0].size())
			adj.push_back(position(cur.x,cur.y+1));

		// for every adjacent node to cur
		for (position next : adj)
		{
			// only proceed if the position isn't blocked
			if (grid[cur.x][cur.y] == '#')
				continue; // blocked, so skip this position

			// if the node hasn't been seen before
			if (distance[next.x][next.y] == -1)
			{
				// visit the adjacent node
				todo.push(next);
				distance[next.x][next.y] = distance[cur.x][cur.y] + 1;
			}
		}
	}
	
	return distance[b_loc.x][b_loc.y];
}

int main()
{
	// Create the maze:
	// #.#.###.a
	// #...##..#
	// #.#....##
	// #b#.#..##
	vector<vector<char>> maze =
		{
		{'#','.','#','.','#','#','#','.','a'},
		{'#','.','.','.','#','#','.','.','#'},
		{'#','.','#','.','.','.','.','#','#'},
		{'#','b','#','.','#','.','.','#','#'}
		};

	cout << "distance from a to b is " << find_distance(maze,'a','b') << endl;
}
