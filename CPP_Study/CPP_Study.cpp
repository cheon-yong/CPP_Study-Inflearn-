#include <iostream>
using namespace std;

// 오늘의 주제 : 참조

struct StatInfo
{
	int hp; // +0
	int attack; // +4
	int defence; // +8
};

void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}

// 값을 수정하지 않는다면 양쪽 다 문제가 없음

// 1) 값 전달 방식
void PrintInfoByCopy(StatInfo info)
{
	cout << "----------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATTACK : " << info.attack << endl;
	cout << "DEFENCE : " << info.defence << endl;
	cout << "----------------" << endl;
}

// 2) 주소 전달 방식
void PrintInfoByPtr(StatInfo* info)
{
	cout << "----------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATTACK : " << info->attack << endl;
	cout << "DEFENCE : " << info->defence << endl;
	cout << "----------------" << endl;
}

// 3) 참조 전달 방식
void PrintInfoByRef(StatInfo& info)
{
	cout << "----------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATTACK : " << info.attack << endl;
	cout << "DEFENCE : " << info.defence << endl;
	cout << "----------------" << endl;
}


// StatInfo 구조체가 1000바이트짜리 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사된다?
// - (주소 전달) StatInfo는 여전히 8
// - (참조 전달) StatInfo&는 8바이트

// 값 전달처럼 편리하게 사용하고!
// 주소 전달처럼 주소값을 이용해 진짜를 건드리는!
// 일석이조의 방식!

int main()
{
	// 4바이트 정수형 바구리는 사용할 예정
	// 앞으로 바구니 이름은 number
	// nubmer를 쓸 때는 알아서 찾아서 1을 넣어줘
	int number = 1;

	// * 
	// int 그 바구니를 따라가면 int형 데이터가 있음
	int* pointer = &number;
	//pointer 바구니에 있는 주소를 타고 이동해서, 그 멀리 있는 바구니에 2를 넣음
	*pointer = 2;


	// 로우레벨 (어셈블리) 관점에서 실제 작동 방식은 int*와 같음
	// 
	int& reference = number;

	// C++ 관점에서는 number라는 바구이네 또 다른 이름을 부여한 것
	// number라는 바구이네 reference라는 다른 이름을 지어줄게
	// 앞으로 reference라는 바구니에 뭘 꺼내거나 넣으면
	// 실제 number 바구니(진짜)에 그 값을 꺼내거나 넣으면 됨

	reference = 3;

	// 그런데 또 다른 이름을 짓는 이유는?
	// 참조 전달 때문

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByRef(info);

	return 0;
}
