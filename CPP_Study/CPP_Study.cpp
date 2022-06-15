#include <iostream>
using namespace std;

// 오늘의 주제 : 배열

struct StatInfo
{
	int hp = 100; // +0
	int attack = 10; // +4
	int defence = 5; // +8
};

int main()
{
	// TYPE 이름[개수];

	// 배열의 크기는 상수여야 함 (VC 컴파일러 기준)
	StatInfo monsters[10];

	// 여태껏 변수들의 [이름]은 바구니의 이름이었음

	// 그러나 배열은 다르게 동작
	// 배열의 이름은 곧 배열의 시작 주소
	// 정확히는 시작 위치를 가리키는 TYPE* 포인터

	auto WhoAmi = monsters;

	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 30 * (i + 1);
		monster.defence = (i + 1);
	}

	// 근데 *(monsters i) 너무 불편하고 가독성이 떨어진다
	// 인덱스!
	// 배열은 0부터 시작 N번째 인덱스에 해당하는 데이터에 접근하려면 배열이름[N]
	// *(mosters + i) = monsters[i]

	for (int i = 0; i < 10; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 30 * (i + 1);
		monsters[i].defence = (i + 1);
	}

	// 배열 초기화 문법 몇가지
	int numbers[5] = {}; // 0으로 초기화
	int numbers1[10] = { 1, 2, 3, 4, 5 }; // 설정하는 애들은 설정한 값들로 나머지 값들은 0으로
	int numbers2[] = { 1,2,3,4,5,6,11,13,15,1 }; // 데이터 수 만큼의 크기만큼 배열로 생성

	char helloStr[] = { 'H', 'e', 'l', 'l', 'o', '\0' };

	// 배열 요약:
	// 1) 선언한다
	int arr[10] = {};

	// 2) 인덱스로 접근해서 사용
	arr[1] = 1;
	cout << arr[1] << endl;


	return 0;
}
