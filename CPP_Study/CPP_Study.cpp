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

// 문제3) 문자열 덧붙이는 함수
void StrCat(char* dest, char* src)
{
	int i = 0;
	while (*dest)
		dest++;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

// 문제4) 문자열 비교
int StrCmp(char* a, char* b)
{
	int i = 0;
	while (a[i] && b[i])
	{
		if (a[i] > b[i])
			return 1;
		if (a[i] < b[i])
			return -1;
			
		i++;
	}

	return 0;
}

// 문제5) 문자열을 뒤집는 함수
void ReverseStr(char* str)
{
	int len = StrLen(str);

	for (int i = 0; i < len / 2; i++)
	{
		int temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

#pragma warning(disable: 4996)
int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	int len = StrLen(a);
	cout << len << endl;
	char b[BUF_SIZE] = "Hello";
	// StrCpy(b, a);
	
	//StrCat(a, b);
	ReverseStr(a);
	cout << a << endl;
	//cout << StrCmp(a, b) << endl;

	return 0;
}
