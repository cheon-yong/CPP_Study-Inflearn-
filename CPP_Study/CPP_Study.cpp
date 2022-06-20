#include <iostream>

using namespace std;


// 오늘의 주제 : 객체 지향 마무리

// 1) struct vs class

// C++ 에서는 struct 나 class 나 큰 차이가 없음
// struct는 기본 접근 지정자가 public이고, class는 private이다
// C++는 C언어에서 파생되어 발전했기 때문에 호환성을 지키기 위함
// -> struct는 그냥 주고체 (데이터 묶음)을 표현하는 용도
// -> class 객체 지향 프로그래밍의 특징을 나타내는 용도



struct TestStruct
{
	int _a;
	int _b;
};

class TestClass
{
	int _a;
	int _b;
};


// 2) static 변수, static 함수 (static = 정적 = 고정된)

class Marine
{
public:
	int _hp;

	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	static void SetAttack()
	{
		s_attack = 100;
	}

	// 특정 마린 객체와는 무관
	// 마린이라는 '클래스' 자체와 연관
	static int s_attack; // 설계도상으로만 존재
};

int Marine::s_attack = 0;

class Player
{
public:
	int _id;
};

int GenerateId()
{
	// 생명주기 : 프로그램 시작/종료 (메모리에 항상 올라가 있음)
	// 가시범위 : 

	// 정적 지역 객체, 처음 호출 됐을 때만 초기화되고 이후 유지
	//1 2 3 4 5...
	static int s_id = 1;


	return s_id++;
}

int main()
{
	Marine m1;
	m1._hp = 40;
	Marine::s_attack = 6;

	Marine m2;
	m2._hp = 40;

	// 마린 공격력 업그레이드 완료! (Academy에서 업그레이드 끝!)
	Marine::s_attack = 7;
	Marine::SetAttack();

	// 스택 아님. .data 영역
	static int id = 10;
	int a = id;

	return 0;
}
