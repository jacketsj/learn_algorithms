// Include this so that we can use IO
#include <iostream>

using namespace std;

int main()
{
	// Output "Hello World!" and a newline into standard out
	cout << "Hello world!" << endl;

	// Output the string "0 1 2 3 4" and a newline into standard out
	for (int i = 0; i < 5; i++)
	{
		// output i, then output a space character
		cout << i << ' ';
	}
	cout << endl;

	// TODO: Output the odd numbers in the inclusive range [-5,11], followied by a newline
}
