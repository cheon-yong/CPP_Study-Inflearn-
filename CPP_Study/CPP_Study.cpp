#include <iostream>

using namespace std;


// 오늘의 주제 : 타입 변환 (포인터)

class Knight
{
public:
	int _hp = 100;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int itemType)" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Item" << endl;
	}
public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {}; // 이런 저런 정보들로 인해 비대해진...무언가...
};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
		_damage = rand() % 100;
	}
	~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Weapon" << endl;
	}
public:
	int _damage;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}
	~Armor()
	{
		cout << "~Armor()" << endl;
	}
};

void TestItemPtr(Item* item)
{
	item->Test();
}

int main()
{
	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{
		// Stack [주소] -> Heap [_hp(4)]
		Knight* knight = new Knight();

		// 암시적으로는 NO
		// 명시적으로는 OK

		// Stack [주소] -> Heap [_hp(4)]
		/*Item* item = (Item*)knight;
		item->_itemType = 2;
		item->_itemDbId = 3;*/

		delete knight;
	}

	// 부모 -> 자식 변환 테스트
	{

		Item* item = new Item();
		Weapon* weapon = (Weapon*)item;

		delete item;
	}

	// 자식 -> 부모 변환 테스트
	{
		Weapon* weapon = new Weapon();

		// 암시적으로 가능
		Item* item = weapon;
		TestItemPtr(item);
	}

	// 명시적으로 타입 변환할 때는 항상 조심해야함ㄴ
	// 암시적으로 딜 때는 안전하다?
	// -> 평생 명시적으로 타입 변환(캐스팅)은 안하면 되는거 아닌가?

	Item* inventory[20] = {};

	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2 + 1;
		switch (randValue)
		{
		case IT_WEAPON:
			inventory[i] = new Weapon();
			break;
		case IT_ARMOR:
			inventory[i] = new Armor();
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}

	// ******************************매우 매우 매우 매우 중요 *****************************
	// 최상위 부모클래스의 소멸자에는 virtual을 붙일 것
	// 이유?) 상속 받은 클래스의 함수를 virtual 없이 재정의할 경우 부모클래스로 형변환했을 때 부모클래스의 함수만 호출된다.
	// 이 것이 소멸자에도 동일하게 적용되어 부모클래스의 소멸자면 호출되는데 이럴 경우 메모리가 모두 지워지지 않게 된다.
	// 이러한 현상을 방지하기 위하여 소멸자에 virtual 키워드를 붙여 자식클래스가 부모클래스로 형변환 되더라도 
	// 자식클래스의 소멸자와 부모클래스의 소멸자가 모두 호출되게 한다.
	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		delete item;
	}

	// [결론]
	// - 포인터 vs 일반 타입 : 차이를 이해하자
	// - 포인터 사이의 타입 변환(캐스팅)을 할 때는 매우 매우 조심해야 한다!
	// - 부모-자식 관계에서 부모 클래스의 소멸자에는 잊어버리지 말고 virtual을 붙이자
	return 0;
}
