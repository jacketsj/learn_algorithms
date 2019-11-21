#include <iostream>
#include <string>

using namespace std;


// Count the numbers in the range [l,r] that are divisble by k
// Uses recursion to break down the problem
int num_div(int l, int r, int k)
{
	// base case
	if (l > r) // is the range empty?
		return 0; // nothing in an empty range

	// otherwise, let's look at the first number, l
	int count = 0;
	// is l divisible by k?
	if (l % k == 0)
		++count;

	// recurse on the rest of the numbers
	return count + num_div(l+1,r,k);
}

// Apply the Caesar shift by k operation to a string
// e.g. caesar_shift("abc",1)="bcd", caesar_shift("abc",-1")="zab"
// By adding the '&' in front of str, the string is passed by reference
// 		(editing changes the original)
// default i=0, since we want to iterate through the string recursively
void caesar_shift(string &s, int k, int i=0)
{
	// base case
	if (i >= s.size()) // have we iterated through all the characters already?
		return;

	// apply the caesar shift
	s[i] = (('a' + (k % 26) + 26) % 26) + 'a';

	// TODO: Recurse
}

int main()
{
	// Use our recursive functions
	cout << "There are " << num_div(-20,40,6) <<
		" numbers divisible by 6 in the range [-20,40]" << endl;

	cout << "caesar_shift(\"abc\",1)=\"" << caesar_shift("abc",1) << "\"\n";
	cout << "caesar_shift(\"abc\",-1)=\"" << caesar_shift("abc",-1) << "\"\n";
	cout << "caesar_shift(\"jack\",4)=\"" << caesar_shift("jack",4) << "\"\n";
}
