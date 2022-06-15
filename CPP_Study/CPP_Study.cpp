#include <iostream>
using namespace std;

// 오늘의 주제 : 로또 번호 생성기

// 1) Swap 만들기
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


// 2) Sort 만들기
void Sort(int numbers[],int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = i; j < count; j++)
		{
			if (numbers[i] > numbers[j])
				Swap(&numbers[i], &numbers[j]);
		}
	}
}

// 3) 로또 번호 생성
void ChooseLotoo(int numbers[])
{
	// TODO : 랜덤으로 1 ~ 45 사이의 숫자 6개를 골라주세요!
	int madeNumber = 0;
	while (madeNumber < 6)
	{
		int num = (rand() % 45) + 1;

		bool isExist = false;
		for (int i = 0; i < madeNumber; i++)
		{
			if (numbers[i] == num)
			{
				isExist = true;
				break;
			}
		}

		if (isExist)
			continue;

		numbers[madeNumber] = num;
		madeNumber++;
	}

	Sort(numbers, 6);
}
int main()
{
	srand(time(0));
	int numbers[6] = {};
	ChooseLotoo(numbers);

	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
	return 0;
}
