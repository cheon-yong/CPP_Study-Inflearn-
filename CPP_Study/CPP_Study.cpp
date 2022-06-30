#include <iostream>
using namespace std;

// 오늘의 주제 : auto

class Knight
{
public :
	int _hp;
};

int main()
{
	int a = 3;
	float b = 3.14;
	double c = 1.23;
	Knight d = Knight();
	const char* e = "rookiss";

	// auto는 일종의 조커카드
	// 형식 연역 (type deduction)
	// -> 말이 되게 잘 맞춰봐 (추론)
	// 추룐 규칙은 생각보다 복잡해질 수 있다

	auto a = 3;
	auto b = 3.14;
	auto c = 1.23;
	auto d = Knight();
	auto e = "rookiss";

	auto f = &d;
	const auto test1 = b;
	

	// 주의!
	// 기본 auto는 const & 무시한다

	int& reference = a;
	const int cst = a;

	auto test1 = reference; // int test1
	auto test2 = cst;       // int test2
	
	auto& test3 = reference;
	const auto test4 = cst;
	return 0;
}
