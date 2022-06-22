#include <iostream>
using namespace std;
#include <vector>
#include <list>


// 오늘의 주제 : list


// vector : 동적 배열
// [               ]

// 단일 / 이중 / 원형
// list : 연결 리스트

// 한칸을 노드라고 함
// [1]  ->  [2]  ->  [3]  ->  [4]  ->  [5]
// 리스트는 연결된 노드들의 집합체
class Node
{
public:
	Node* _next;
	int _data;

};

class Node2
{
public:
	//Node2 _next; // 말이 안됨
	int _data;
};

int main()
{
	// list (연결 리스트)
	// - list의 동작 원리
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	list<int> li;

	for (int i = 0; i < 100; i++)
		li.push_back(i + 1);

	li.size();
	//li.capacity();
	li.push_front(10);
	li.push_back(10);
	li.front();
	li.back();

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	for (list<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);

	li.erase(li.begin());

	li.pop_front();

	li.remove(10);

	return 0;
}
