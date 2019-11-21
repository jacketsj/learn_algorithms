#include <iostream>
#include <string>
// A vector is a variable-length array, similar to an ArrayList in Java
#include <vector>

using namespace std;

// Sum all of the numbers in the given array
int sum_of_numbers(const vector<int> &arr)
{
	int sum = 0;
	// This is a for-each loop
	// It iterates through every element in arr
	for (int val : arr)
		sum += val;

	return sum;
}

// Increment all of the numbers in the given array
int inc_each(vector<int> &arr)
{
	// This for-each loop uses references, so that we can edit the elements of the array
	for (int &val : arr)
		val++;
}

// Increment every other element of the array, starting with the first
int inc_every_other(vector<int> &arr)
{
	// We don't always want to use for-each loops on arrays.
	// Sometimes normal for-loops are necessary
	// Add 2 to i to skip elements
	for (int i = 0; i < arr.size(); i += 2)
		arr[i]++;
}

// Compute the product of every other element of an array, starting with the first
int product_of_every_other(const vector<int> &arr)
{
	int prod = 1;

	// TODO: Loop over the elements correctly

	return prod;
}

void print_vector(string name, const vector<int>& v)
{
	cout << name << ": ";
	for (int val : v)
		cout << val << ' ';
	cout << endl;
}

int main()
{
	// We can initialize vectors with initialization lists, or with sizes
	vector<int> example1 = {1,2,3,4}, example2 = {4,5}, example3(4), example4(2,20);

	print_vector("example1", example1);

	print_vector("example2", example2);

	// The parameter for example3 was the size.
	// Every element defaulted to 0
	print_vector("example3", example3);

	// The second parameter for example4 was the default value
	print_vector("example4", example4);

	cout << "sum of example1=" << sum_of_numbers(example1) << endl;
	cout << "incrementing example1" << endl;
	inc_each(example1);
	print_vector("example1 after incrementation", example1);
	cout << "incrementing every other of example1" << endl;
	inc_every_other(example1);
	print_vector("example1 after every other incrementation", example1);
	cout << "product of every other of example1: " << product_of_every_other(example1);
}
