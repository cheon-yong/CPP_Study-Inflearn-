#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>

// 오늘의 주제 : map

class Player
{
public:
	Player() : _playerId(0) { }
	Player(int playerId) : _playerId(playerId) { }
public:
	int _playerId;
};

int main()
{
	// 연관 컨테이너	

	// map : 균형 이진 트리 (AVL)
	// - 노드 기반

	class Node
	{
	public:
		Node* _left;
		Node* _right;

		pair<int, Player*> _data;
		//int _key;
		//Player* _value;
	};
	srand(static_cast<unsigned int>(time(nullptr)));
	map<int, int> m;

	m.insert(make_pair(1, 100));
	m.insert(make_pair(1, 200)); // key 중복 불가

	// 10만명 입장
	for (int i = 0; i < 100000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5만명 퇴장
	for (int i = 0; i < 50000; i++)
	{
		int randomValue = rand() % 50000;

		// Erase By Key
		m.erase(randomValue);
	}

	// Q) ID = 1만인 Player를 찾고 싶다!
	// A) 매우 빠르게 찾을 수 있음

	map<int, int>::iterator findIt = m.find(10000);
	if (findIt != m.end())
	{
		cout << "찾음" << endl;
	}
	else
	{
		cout << "못찾음" << endl;
	}
	
	// map 순회
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		pair<const int, int>& p = (*it);
		int key = p.first; // (*it).first it->first
		int value = p.second;

		cout << key << " " << value << endl;
	}

	// 없으면 추가, 있으면 수정
	map<int, int>::iterator findIt = m.find(10000);
	if (findIt != m.end())
	{
		findIt->second = 200;
	}
	else
	{
		m.insert(make_pair(10000, 200));
	}

	// 없으면 추가, 있으면 수정 v2
	m[5] = 500; // 5라는 key가 있으면 500으로 수정, 없으면 (5, 500) 추가
	
	m.clear();

	// [] 연산자 사용할 때 주의
	// 대입을 하지 않더라도 (Key/Value) 형태의 데이터가 추가된다!
	// 즉 없으면 기본값으로 세팅해줌
	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;

	}

	// 넣고   (insert, [])
	// 빼고   (erase)
	// 찾고   (find, [])
	// 반복자 (map::iterator) (*it) pair<key, value>&
	return 0;
}
