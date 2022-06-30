#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
// 오늘의 주제 : 알고리즘
#include <algorithm>

// 자료구조 (데이터를 저장하는 구조)
// 알고리즘 (데이터를 어떻게 사용할 것인가?)

// find
// find_if
// count
// count_if
// all_of
// any_of
// none_of
// for_each
// remove
// remove_if

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// Q1) number라는 숫자가 벡터에 체크하는 기능 (bool, 첫 등장 iterator)
	{
		int number = 50;
		bool found = false;
		vector<int>::iterator it;

		// TODO
		for (it = v.begin(); it != v.end(); ++it)
		{
			if ((*it) == number)
			{
				found = true;
				break;
			}
		}

		vector<int>::iterator itFind = find(v.begin(), v.end(), number);
		if (itFind == v.end())
		{
			cout << "Q1 못찾았음" << endl;
		}
		else
		{
			cout << "Q1 찾았음" << endl;
		}
	}
	
	// Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능 (bool, 첫 등장 iterator)
	{
		bool found = false;
		vector<int>::iterator it;
		// TODO
		for (it = v.begin(); it != v.end(); ++it)
		{
			if ((*it) % 11 == 0)
			{
				found = true;
				break;
			}
		}

		struct CanDivideBy11
		{
			bool operator() (int n)
			{
				return (n % 11) == 0;
			}
		};

		vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivideBy11());
		if (itFind == v.end())
		{
			cout << "Q2 못찾았음" << endl;
		}
		else
		{
			cout << "Q2 찾았음" << endl;
		}
	}
	// Q3) 홀수인 숫자의 개수는? (count)
	{
		int count = 0;
		int size = v.size();
		for (int i = 0; i < size; i++)
		{
			if (v[i] % 2 == 1)
				count++;
		}

		struct IsOdd
		{
			bool operator() (int n)
			{
				return (n % 2) != 0;
			}
		};
		int n = count_if(v.begin(), v.end(), IsOdd());
		
		cout << "Q3 n : " << n << endl;


		bool b1 = all_of(v.begin(), v.end(), IsOdd());
		cout << b1 << endl;
		bool b2 = any_of(v.begin(), v.end(), IsOdd());
		cout << b2 << endl;
		bool b3 = none_of(v.begin(), v.end(), IsOdd());
		cout << b3 << endl;
	}
	// Q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱해주세요
	{
		int size = v.size();
		for (int i = 0; i < size; i++)
		{
			v[i] *= 3;
		}

		struct MultiplyBy3
		{
			void operator()(int& n)
			{
				n = n * 3;
			}
		};

		for_each(v.begin(), v.end(), MultiplyBy3());
	}

	// 홀수인 데이터를 일괄 삭제
	{
		v.clear();

		v.push_back(1);
		v.push_back(4);
		v.push_back(3);
		v.push_back(5);
		v.push_back(8);
		v.push_back(2);

		// 1 4 3 5 8 2

		remove(v.begin(), v.begin(), 4);

		struct IsOdd
		{
			bool operator() (int n)
			{
				return (n % 2) != 0;
			}
		};

		vector<int>::iterator it = remove_if(v.begin(), v.begin(), IsOdd());
		v.erase(remove_if(v.begin(), v.begin(), IsOdd()), v.end());
		
	}
	return 0;
}
