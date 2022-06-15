#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 vs 배열

void Test(int a)
{
	a++;
}

// 배열은 함수 인자로 넘기면, 컴파일러가 알아서  포인터로 치환한다 (char[] -> char*)
// 배열 내용 전체를 넘긴 것이 아니라 주소를 넘김
void Test(char a[])
{
	a[0] = 'x';
}

int main()
{
	// 문자열 = 문자 배열
	/*cout << "Hellow World" << endl;

	char msg[] = { 'H', 'e', 'l','l', 'o', '\0'};
	cout << msg << endl;*/

	// test1[ 주소 ] << 8바이트 (주소크기, 32bit 운영체제는 4바이트)
	// .data 주소[H][e][l][l].....[d][\0]
	const char* test1 = "Hello World";

	// .data 주소[H][e][l][l].....[d][\0]
	// [][][]....[][]  12개짜리 변수배열
	// [H][e][l][l].....[d][\0]
	// test2 = 주소
	char test2[] = "Hello World";
	test2[0] = 'R';

	cout << test2 << endl;

	// 포인터는 [주소를 담는 바구니]
	// 배열은 [닭장] 즉, 그 자체로 같은 데이터끼리 붙어있는 '바구니 모음'
	// - 다만 [배열 이름]은 '바구니 모음'의 [시작주소]

	// 배열을 함수의 인자로 넘기게 되면?

	int a = 0;
	Test(a);

	cout << a << endl;

	Test(test2);
	cout << test2 << endl;
	
	return 0;
}
