// Include this so that we can use IO
#include <iostream>

int main()
{
	// Output "Hello World!" and a newline into standard out
	cout << "Hello world!" << endl;

	// Output the string "0 1 2 3 4 5 6 7 8 9" and a newline into standard out
	for (int i = 0; i < 10; i++)
		cout << i << ' ';
	cout << endl;

	// TODO: Output the odd numbers in the inclusive range [-5,11], followied by a newline
	// Solution: Use a for loop simiarly to before, but increment by 2 each time
	for (int i = -5; i <= 11; i+=2)
		cout << i << ' ';
	cout << endl;
}
