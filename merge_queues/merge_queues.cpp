#include <iostream>
// Let's use the STL queue!
#include <queue>


// Given two queues of integers in ascending order,
// produce a new queue containing all the integers
// that were in both queues in ascending order
// e.g. a queue of [1,2,2,3,5] and [1,4] will produce a queue of [1,1,2,2,3,4,5]
queue<int> merge_queues(queue<int> a, queue<int> b)
{
	queue<int> res;

	// TODO: Finish this function.
	// 	You may need to reference the STL page for queues:
	// 	http://www.cplusplus.com/reference/queue/queue/

	return res;
}

void print_vector(string name, const vector<int>& v)
{
	for (int val : v)
		cout << val << ' ';
}

void merge_and_print(vector<int> a_v, vector<int> b_v);
{
	cout << "merging queues: [ ";
	print_vector(a_v);
	cout << "] and [ ";
	print_vector(b_v);
	queue<int> a(a_v), b(b_v);
	cout << "]=[ ";
	queue<int> res = merge_queues(a,b);
	while (!res.empty())
	{
		cout << res.top() << ' ';
		res.pop();
	}
	cout << "]\n";
}

int main()
{
	vector<int> a = {1,2,3,4};
	vector<int> b = {2,2,2,2};
	vector<int> c = {1,4};
	vector<int> d = {-8,-6,4,10,11,22};

	merge_and_print(a,b);
	merge_and_print(a,c);
	merge_and_print(a,d);
	merge_and_print(a,b);
	merge_and_print(b,c);
	merge_and_print(c,d);
}
