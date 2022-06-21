#include <iostream>
#include <stdlib.h>
using namespace std;

// 오늘의 주제 : 함수 포인터

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{
public:
	Item() : _itemId(0), _rarity(0), _ownerId(0)
	{

	}

	virtual ~Item()
	{

	}

public:
	int _itemId; // 아이템을 구분하기 위한 ID
	int _rarity; // 희귀도
	int _ownerId; // 소지자 ID
};
typedef bool(ITEM_SELECTOR)(Item*, int);

// ==, ITEM_SELECTOR* selector
Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		if (selector(item, value))
			return item;
	}

	return nullptr;
}

bool IsRareItem(Item* item, int value)
{
	return item->_rarity >= value;
}

bool isOwnerItem(Item* item, int ownerId)
{
	return item->_ownerId == ownerId;
}

int main()
{
	int a = 10;

	// 바구니 주소
	// pointer[ 주소 ] -> 주소 [   ]

	typedef int DATA;

	// 1) 포인터      *
	// 2) 변수 이름   pointer
	// 3) 데이터 타입 int
	DATA* pointer = &a;

	typedef int (FUNC_TYPE)(int, int);
	
	// 1) 포인터      *
	// 2) 변수 이름   fn
	// 3) 데이터 타입 함수 (인자 int, int 반환은 int)
	FUNC_TYPE* fn;

	fn = Add;
	fn = Sub;

	// 함수의 이름은 함수의 시작 주소 (배열과 유사)
	int result = fn(1, 2); // 기본 문법
	cout << result << endl;

	int result2 = (*fn)(1, 2); // 함수 포인터는 *(접근 연산자)를 붙여도 함수 주소
	cout << result2 << endl;

	Item items[10] = {};
	items[3]._rarity = 2;
	Item* rareItem = FindItem(items, 10, IsRareItem, 2);
	return 0;
}
