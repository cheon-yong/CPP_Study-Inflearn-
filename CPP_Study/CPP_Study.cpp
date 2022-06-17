#include <iostream>
using namespace std;

// 오늘의 주제 : 연습문제 (문자열) #1

// 문제1) 문자열 길이를 출력하는 함수
int StrLen(const char* str)
{
	int len = 0;
	while (str[len] != 0)
	{
		len++;
	}

	return len;
}

// 문제2) 문자열 복사 함수
void StrCpy(char* dest, char* src)
{
	int i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

//

#pragma warning(disable: 4996)
int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	int len = StrLen(a);
	cout << len << endl;
	char b[BUF_SIZE] = "World";
	// StrCpy(b, a);
	
	cout << b << endl;
	len = StrLen(a);
	cout << len << endl;

	return 0;
}
