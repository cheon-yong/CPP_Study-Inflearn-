#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <algorithm>
#include <set>

// 오늘의 주제 : delete (삭제된 함수)

class Knight
{
public:

public:
	// 정의되지 않은 비공개(private) 함수
	void operator=(const Knight& k) = delete;
	

	// 모든 것은 뚫는 창 vs 절대 방패
	friend class Admin;


private:
	int _hp = 100;
};

class Admin
{
public:
	void CopyKnight(const Knight& k)
	{
		Knight k1;
		// 복사 연산
		k1 = k;
	}
};

int main()
{
	Knight k1;

	Knight k2;

	return 0;
}