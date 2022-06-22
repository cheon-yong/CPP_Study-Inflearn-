#include <iostream>
using namespace std;
#include <vector>
#include <list>


// 오늘의 주제 : list


// vector : 동적 배열
// [               ]



class Node
{
public:
	Node* _next;
	Node* _prev;
	int _data;
};

// 단일 / 이중 / 원형
// list : 연결 리스트

// 한칸을 노드라고 함
// [1]   ->  [2]   ->  [3]   ->  [4]   ->  [5]
// [1]  <->  [2]  <->  [3]  <->  [4]  <->  [5] <-> [ _MyHead : end() ] <-> [
// [1]  <->  [2]  <->  [3]  <->  [4]  <->  [5]
// 리스트는 연결된 노드들의 집합체

int main()
{
	// list (연결 리스트)
	// - list의 동작 원리
	// 포인터를 이용해서 다음 노드로 이동 (즉 배열처럼 메모리상에 데이터가 몰려있지 않음)
	// - 중간 삽입/삭제 (GOOD / GOOD)
	// - 처음/끝 삽입/삭제 (GOOD / GOOD)
	// - 임의 접근 (i번째 데이터는 어디 있습니까?) li[3] 불가능

	// --begin() 불가능
	// --end() 가능
	// ++end() 불가능
	// begin() + i 불가능

	list<int> li;

	for (int i = 0; i < 100; i++)
		li.push_back(i + 1);

	//li.size();
	//li.capacity();
	//li.push_front(10);
	//li.push_back(10);
	//li.front();
	//li.back();

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	for (list<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << *it << endl;
	}

	/*li.insert(itBegin, 100);

	li.erase(li.begin());

	li.pop_front();

	li.remove(10);*/

	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50; i++)
		++it;

	li.erase(it);
	for (list<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}
