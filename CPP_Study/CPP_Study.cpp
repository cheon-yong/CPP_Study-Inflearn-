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

	}

	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}

	~Item()
	{
		cout << "~Item()" << endl;
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
	}
	~Weapon()
	{
		cout << "~Weapon()" << endl;
	}
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
	return 0;
}
