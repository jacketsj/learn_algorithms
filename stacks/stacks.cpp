#include <iostream>
#include <vector>

// Let's implement a stack!
// Let's do it with a vector

struct int_stack
{
	// the end of vals will be the top of our stack
	vector<int> vals;

	// push a new element to the stack
	void push(int val)
	{
		// increment the size of vals and add val to the back of it
		vals.push_back(val);
	}

	// get the element on top (don't pop it)
	int top()
	{
		if (vals.size() == 0) // there's nothing on top
		{
			cerr << "tried to access empty stack!" << endl;
			assert(0); // crash
		}
		return vals[vals.size()-1];
	}

	// pop the element on top
	void pop()
	{
		if (vals.size() == 0) // there's nothing on top
		{
			cerr << "tried to access empty stack!" << endl;
			assert(0); // crash
		}
		// remove the last element of vals
		vals.pop_back();
	}
};

void print_vector(string name, const vector<int>& v)
{
	cout << name << ": ";
	for (int val : v)
		cout << val << ' ';
	cout << endl;
}

int main()
{
	vector<int> numbers = {1,2,3,4,5,6};
	print_vector("numbers initially", numbers);

	// TODO: using the stack, reverse list of the numbers

	print_vector("numbers revsered", numbers);
}
