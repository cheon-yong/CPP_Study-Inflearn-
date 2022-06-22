#include <iostream>
using namespace std;
#include <vector>


// 오늘의 주제 : vector
int main()
{
	// STL (Standard Template Library)
	// 프로그래밍할 때 필요한 자료구조/알고리즘들을
	// 템플릿으로 제공하는 라이브러리

	// 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	// 반복자(Iterator) : 포인터와 유사한 개념, 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로 이동 가능
	vector<int> v(10);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		v[i] = i;

	/*vector<int>::iterator it;
	int* ptr;

	it = v.begin();
	ptr = &v[0];

	cout << (*it) << endl;
	cout << *ptr << endl;

	it++;
	++it;

	ptr++;
	++ptr;

	it--;
	--it;

	ptr--;
	--ptr;

	it += 2;
	it = it - 2;

	ptr += 2;
	ptr = ptr - 2;

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();*/

	// 더 복잡해보이는데?
	// // 다른 컨테이너는 v[i]와 같은 인덱스 접근이 안될 수도 있음
	// iterator는 vector뿐만 아니라, 다른 컨테이너에도 공통적으로 있는 개념
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}
	int* ptrBegin = &v[0];
	int* ptrEnd = ptrBegin + 10;

	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
	{
		cout << (*ptr) << endl;
	}

	//vector<int>::const_iterator cit1 = v.cbegin();
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	{
		cout << (*it) << endl;
	}


	// - 중간 삽입/삭제 (BAD) 중간점을 기준으로 모든 요소를 움직이기 때문
	// - 처음/끝 삽입/삭제 (처음 삽입/삭제는 BAD / 끝 삽입/삭제는 GOOD)
	// - 임의 접근(Random Access)

	// vector = 동적 배열 = 동적으로 커지는 배열 = 배열
	// 원소가 하나의 메모리 블록에 연속하게 저장된다!!

	// [                     ]
	// [                                ]

	// i번째 데이터에 접근 (임의접근)
	// v[i] = 3; 

	//vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);
	//vector<int>::iterator eraseIt = v.erase(v.begin() + 2);
	//vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4);

	// 벡터를 스캔하면서 3이라는 데이터가 있으면 일괄삭제하고 싶다!

	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		int data = *it;
		if (data == 3)
		{
			it = v.erase(it); // 삭제된 곳의 iterator를 반환
			// v.erase(it); // 문제 발생
			// break;
		}
		else
		{
			++it;
		}
		
		// iterator를 erase하게 되면 사용하고 있는 iterator가 null로 처리가 됨
		// 그렇게 때문에 v.erase(it)를 했을 때 반환해주는 it를 이용해서 이후 처리를 해야하며
		// for문에 무조건 ++it를 해주면 연속으로 지워주고 싶은 값이 올 경우 누락될 수 있음
		// ex)
		// 1 2 3 3 4 5 6
		//     it
		// -------erase-------
		// 1 2 3 4 5 6
		//     it
		// ------- ++it -------
		// 1 2 3 4 5 6 
		//       it

		// 그렇기 때문에 else로 ++it처리 해주어야함
		
	}
	
	return 0;
}
