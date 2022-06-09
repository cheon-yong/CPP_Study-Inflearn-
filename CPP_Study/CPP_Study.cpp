#include <iostream>
using namespace std;

int main()
{
	//exercise1
	/*int input;
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			cout << "*";
		}
		cout << endl;
	}*/

	//exercise2
	/*int input;
	cin >> input;

	for (int i = 1; i <= input; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}*/
	
	//exercise3
	/*int input;
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}*/

	//exercise4
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}
}