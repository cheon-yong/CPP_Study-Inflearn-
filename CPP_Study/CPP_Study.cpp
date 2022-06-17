#include <iostream>
#include <iomanip>
using namespace std;

// 오늘의 주제 : 연습문제

const int MAX = 100;
int board[100][100] = {};
int N;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void PrintBoard()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

enum DIR
{
	RIGHT = 0,
	DOWN,
	LEFT,
	UP,
};

void SetBoard()
{
	int value = 1;
	int dest = N * N;
	int direct = RIGHT;
	int x = 0;
	int y = 0;
	while (value <= dest)
	{
		board[y][x] = value;
		value++;

		int nextX = x + dx[direct];
		int nextY = y + dy[direct];

		if (nextX == N || nextY == N || nextX < 0 || nextY < 0 || board[nextY][nextX] != 0)
		{
			direct = (direct + 1) % 4;
		}

		x += +dx[direct];
		y += +dy[direct];
	}
}

int main()
{
	cin >> N;

	SetBoard();

	PrintBoard();
	return 0;
}
