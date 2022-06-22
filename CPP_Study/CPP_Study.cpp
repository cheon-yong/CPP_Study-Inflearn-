#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>

// 오늘의 주제 : deque


// vector : 동적 배열
// [     ]

// list : 이중 연결 리스트
// [ ] <-> [ ] <-> [ ] <-> [ ]

// deque : double-ended queue 데크 
// [     ]
// [     ]
// [     ]
// 배열이 가득차면 다른 것을 할당하여 연결 
int main()
{
	// 시퀀스 컨테이너 (Sequence Container)
	// 데이터가 삽입 순서대로 나열되는 형태
	// vector list deque

	deque<int> dq;
	dq.push_back(1);
	dq.push_front(2);
	cout << dq[0] << endl;

	// vector와 마찬가지로 배열 기반 동작
	// 다만 메모리 할당 정책이 다르다

	// vector
	// [     ] 이동 후 삭제
	// [                   ]

	// deque
	// [    ]  추가 후 연결
	// [    ] 

	// - deque의 동작 원리
	// - 중간 삽입/삭제 (BAD / BAD) vector와 같은 원리
	// - 처음/끝 삽입/삭제 (GOOD / GOOD)
	// - 임의 접근 (GOOD)

	return 0;
}
