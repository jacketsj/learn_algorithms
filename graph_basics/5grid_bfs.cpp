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
int find_distance(const vector<vector<char>> &grid, char a, char b)
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

	return -1;
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
