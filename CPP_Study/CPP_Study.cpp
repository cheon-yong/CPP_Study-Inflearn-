#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <algorithm>
#include <set>

// 오늘의 주제 : enum class

enum PlayerType : char
{
	None,
	PT_Knight,
	PT_Archer,
	PT_Mage
};

enum MonsterType
{
	// None을 쓸 수 없다!
};

enum class ObjectType
{
	Player,
	Monster,
	Projectile
};

int main()
{
	// enum class (scoped enum)
	// 1) 이름공간 관리 (scoped)
	// 2) 암묵적인 변환 금지

	double value = PT_Knight; // 가능

	// double value2 = ObjectType::Player; // 불가능
	double value2 = static_cast<double>(ObjectType::Player); // 억지로 가능

	int choice;
	cin >> choice;
	// if (choice == ObjectType::Monster) // 불가능
	if (choice == static_cast<int>(ObjectType::Monster))
	{

	}

	unsigned int bitFlag;
	bitFlag = (1 << static_cast<int>(ObjectType::Player));

	return 0;
}