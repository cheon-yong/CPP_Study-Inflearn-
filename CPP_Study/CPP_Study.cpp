#include <iostream>
using namespace std;
#include <vector>
#include <list>

// 오늘의 주제 : using

typedef vector<int>::iterator VecIt;

typedef int id;

using id2 = int;

// 1) 직관성
typedef void (*MyFunc)();
using MyFunc2 = void(*);


// 2) 템플릿
template<typename T>
using List = std::list<T>;


int main()
{
	id playerId = 0;

	List<int> li;
	li.push_back(10);
	li.push_back(10);
	li.push_back(10);
	li.push_back(10);
	li.push_back(10);

	return 0;
}