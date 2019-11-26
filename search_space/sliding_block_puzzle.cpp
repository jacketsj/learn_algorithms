#include <bits/stdc++.h>
using namespace std;

struct grid
{
	vector<vector<int>> v; //size m*n
	bool operator==(grid &other)
	{
		for (int x = 0; x < cur.v.size(); ++x)
			for (int y = 0; y < cur.v[x].size(); ++y)
				if (v[x][y] != other.v[x][y])
					return false;
		return true;
	}
};

vector<grid> next_grids(grid &cur)
{
	//find the 0
	int pos_x, pos_y; //of the 0
	for (int x = 0; x < cur.v.size(); ++x)
		for (int y = 0; y < cur.v[x].size(); ++y)
			if (cur.v[x][y] == 0)
			{
				pos_x = x;
				pos_y = y;
			}
	//figure out which directions it can swap
	vector<grid> ret;
	if (pos_x + 1 < cur.v.size())
	{
		vector<grid> next = cur; //duplicate the vector
		swap(next[pos_x][pos_y],next[pos_x+1][pos_y]); //swap 0
		ret.push_back(next);
	}
	if (pos_x - 1 >= 0)
	{
		vector<grid> next = cur; //duplicate the vector
		swap(next[pos_x][pos_y],next[pos_x-1][pos_y]); //swap 0
		ret.push_back(next);
	}
	// x doesn't change when we add 1 to y
	if (pos_y + 1 < cur.v[pos_x].size())
	{
		vector<grid> next = cur; //duplicate the vector
		swap(next[pos_x][pos_y],next[pos_x][pos_y+1]); //swap 0
		ret.push_back(next);
	}
	if (pos_y - 1 >= 0)
	{
		vector<grid> next = cur; //duplicate the vector
		swap(next[pos_x][pos_y],next[pos_x][pos_y-1]); //swap 0
		ret.push_back(next);
	}
}

vector<grid> next_grid_set(vector<grid> &cur_grids)
{
	vector<grid> res;
	for (grid& g : cur_grids)
	{
		vector<grid> res_g = next_grids(g);
		for (grid& cur_g : res_g)
			res.push_back(cur_g);
	}
	return res;
}

// minimum number of moves to get from start to end
int bfs(grid& start, grid& end)
{
	if (start == end)
		return 0;
	vector<grid> current_set = {start};
	int count = 0;
	unordered_map<grid,bool> visited;
	visited[start] = true;
	while (current_set.empty())
	{
		vector<grid> res_with_visited = next_grid_set(current_set);
		vector<grid> res;
		++count;
		for (grid& g : res)
		{
			if (g == end)
				return count;
			//visited[g] returns false by default if g is not in the map
			if (!visited[g])
			{
				visited[g] = true;
				res.push_back(g);
			}
		}
		current_set = res;
	}
	return -1;
}
