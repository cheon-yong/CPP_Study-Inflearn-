#include <iostream>

using namespace std;


// 오늘의 주제 : 연산자 오버로딩 (Operator Overloading)

// 연산자 vs 함수
// - 연산자는 피연산자의 개수/타입이 고정되어 있음
// 

// 연산자 오버로딩?
// 일단 [연산자 함수]를 정의해야 함
// 함수도 멤버함수 vs 전역함수가 존재하는 것처럼, 연산자 함수도 두 가지 방식으로 가능

// - 멤버 연산자 함수 version
// -- a op b 형태에서 왼쪽을 기준으로 실행됨 (a가 클래스여야 가능. a를 '기준 피연산자'라고 함)
// -- 한계) a가 클래스가 아니면 사용 못함

// - 전역 연산자 함수 version
// -- a op b 형태라면 a, b 모두를 연산자 함수의 피연산자로 만들어준다.

// 무엇이 더 좋은가? -> 의미 없음. 심지어 둘 중 하나만 지원하는 경우도 있기 때문
// - 대표적으로 대입 연산자(a = b)는 전역 연산자 버전으로는 만들 수 없음

// 복사 대입 연산자
// 용어가 헷갈림 [복사 생성자] [대입 연산자] [복사 대입 연산자]
// - 복사 대입 연산자 = 대입 연산자 중, 자기 자신의 참조 타입을 인자로 받는 것

// 기타
// - 모든 연산자를 다 오버로딩 할 수 있는것은 아님 ("" . .* 이런건 불가)
// - 모든 연산자가 다 2개 항이 있는 것은 아님 ++ -- 가 대표적(단항 연산자)
// - 증감 연산자 ++ --
// -- 전위 형 (++a) operator++()
// -- 후위 형 (a++) operator++(int)
class Position
{
public:

	// 복사 생성자
	/*Position(const Position& arg)
	{

	}*/

	Position operator+ (const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;
		return pos;
	}

	Position operator+ (int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;
		return pos;
	}

	bool operator== (const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}

	Position& operator=(int arg)
	{
		_x = arg;
		_y = arg;

		return *this;
	}

	// [복사 생성자] [복사 대입 연산자] 등 특별 대우 받는 이유는
	// 말 그대로 객체가 '복사'되길 원하는 특징 때문
	// TODO ) 동적할당 시간에 더 자세히
	// [복사 대입 연산자]
	Position& operator=(const Position& arg)
	{
		_x = arg._x;
		_y = arg._y;

		return *this;
	}

	Position& operator++()
	{
		_x++;
		_y++;
		return *this;
	}
	
	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;

		return ret;
	}

	void Print()
	{
		cout << _x << " " << _y << endl;
	}

public:
	int _x;
	int _y;

};


Position operator+ (int a, const Position& b)
{
	Position ret;

	ret._x = b._x + a;
	ret._y = b._y + a;

	return ret;
}


int main()
{
	int a = 1;
	int b = 2;

	int c = a + 3.0f;
	

	Position pos;
	pos._x = 0;
	pos._y = 0;
	cout << "pos" << endl;
	pos.Print();

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;
	cout << "pos2" << endl;
	pos2.Print();

	Position pos3 = pos + pos2;
	cout << "pos3" << endl;
	pos3.Print();
	// == pos3 = pos.operator+(pos2);

	Position pos4 = pos3 + 1;
	cout << "pos4" << endl;
	pos4.Print();

	Position pos5 = 1 + pos3; //아직 안됨
	cout << "pos5" << endl;
	pos5.Print();

	bool isSame = (pos3 == pos4);

	Position pos6;
	pos6 = 6;
	cout << "pos6" << endl;
	pos6.Print();

	Position pos7;
	pos7._x = 0;
	pos7._y = 0;
	pos7++;
	cout << "pos7" << endl;
	pos7.Print();
	
	Position pos8;
	pos8._x = 0;
	pos8._y = 0;
	++pos8;
	cout << "pos8" << endl;
	pos8.Print();


	Position pos9;
	cout << "pos9" << endl;
	pos9 = pos7++;
	pos9.Print();

	return 0;
}
