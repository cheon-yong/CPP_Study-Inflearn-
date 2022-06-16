#include <iostream>
using namespace std;

// 오늘의 주제 : 다차원 배열


int main()
{
	int a[10] = { 1, 2, 3 };

	// 
	int apartment2D[2][5] = { {4, 2, 3, 4, 1}, {1, 1, 5, 2, 2} };

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int num = apartment2D[floor][room];
			cout << num << " ";
		}
		cout << endl;
	}
	
	int apartment1D[10] = { 4, 2, 3, 4, 1, 1, 1, 5, 2, 2 }
	return 0;
}
