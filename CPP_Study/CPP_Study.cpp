#include <iostream>
using namespace std;

// 오늘의 주제 : 지역 변수와 값 전달

// 전역 변수
// 참고) 초기화 여부, const 등, .bss .data .rodata
int globalValue = 0;

void Test()
{
	cout << "전역 변수의 값은 : " << globalValue << endl;
	globalValue++;
}

int IncreaseHp(int hp)
{
	int finalHp = hp + 1;
	return finalHp;
}

int main()
{
	cout << "전역 변수의 값은 : " << globalValue << endl;
	globalValue++;

	Test();

	// 지역변수
	int localValue = 0;

	int hp = 1;
	cout << "Increase 호출 전 : " << hp << endl;
	hp = IncreaseHp(hp);
	cout << "Increase 호출 후 : " << hp << endl;

	return 0;
}