#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <algorithm>
#include <set>

// 오늘의 주제 : 오른값(rvalue) 참조와 std::move

class Pet
{

};

class Knight
{
public:
	void PrintInfo() const
	{

	}
	Knight()
	{
		cout << "Knight()" << endl;
	}

	// 복사 생성자

	Knight(const Knight& knight)
	{
		cout << "const Knight&" << endl;
	}


	// 이동생성자


	~Knight()
	{
		if (_pet)
			delete _pet;
	}

	// 복사 대입 연산자
	void operator=(const Knight& knight)
	{
		cout << "operato=(const Knight&)" << endl;

		_hp = knight._hp;

		if (knight._pet)
			_pet = new Pet(*knight._pet);
	}

	// 이동 대입 연산자
	void operator=(Knight&& knight) noexcept
	{
		cout << "operator=(Knight&&)" << endl;

		// 얕은 복사
		_hp = knight._hp;
		_pet = knight._pet;

		knight._pet = nullptr;
	}



public:
	int _hp = 100;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight) { knight._hp = 20; }
void TestKnight_LValueRef(Knight& knight) { knight._hp = 20; }
void TestKnight_ConstLValueRef(const Knight& knight) { knight.PrintInfo(); }
void TestKnight_RValueRef(Knight&& knight) { knight._hp = 20; }

int main()
{

	// 왼값(lvalue) vs 오른값(rvalue)
	// - lvalue : 단일식을 넘어서 계속 지속되는 개체
	// - rvalue : lvalue가 아닌 나머지 (임시 값, 열거형, 람다, i++ 등)

	int a = 3;
	//3 = a; // 불가능
	a = 4;

	Knight k1;

	TestKnight_Copy(k1);
	TestKnight_LValueRef(k1);
	//TestKnight_LValueRef(Knight());

	TestKnight_ConstLValueRef(Knight());
	TestKnight_RValueRef(Knight());
	TestKnight_RValueRef(static_cast<Knight&&>(k1));

	Knight k2;
	k2._pet = new Pet();
	k2._hp = 1000;

	// 원본은 날려도 된다는 힌트를 주는쪽에 가깝다
	Knight k3;
	//k3 = static_cast<Knight&&>(k2);

	k3 = std::move(k2); // 오른값 참조로 캐스팅
	// std::move의 본래 이름 후보 중 하나가 rvalue_cast

	std::unique_ptr<Knight> uptr = std::make_unique<Knight>();
	std::unique_ptr<Knight> uptr2 = std::move(uptr);

	return 0;
}