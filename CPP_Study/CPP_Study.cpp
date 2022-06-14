﻿#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 (프로시저, 메소드, 루틴)
/*
input 으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다

반환타입 함수이름 ([인자타입 매개변수])
{
함수 내용

return ~~~;
}
*/

// Hello World를 콘솔에 출력하는 함수를 만들어보자!
// input : 없음 / output: 없음
// 타입 : int float double char~~

void PrintHelloWorld()
{
	cout << "Hello World" << endl;
}

// 정수를 입력(함수) 받아서, 콘솔에 출력하는 함수를 만들어보자
// input : int / output : 없음

void PrintNumber(int number)
{
	cout << "넘겨주신 숫자는 " << number << "입니다." << endl;
}

// 2를 곱하고 결과물을 뱉는 함수를 만들어보자
// input : int / output : int

int MultiplyBy2(int a)
{
	int result = a * 2;
	return result;
}

// 두 숫자를 곱해서 결과물을 뱉는 함수를 만들어보자
// input : int, int / output int

int MultiplyBy(int a, int b)
{
	return a * b;
}

int main()
{
	PrintNumber(2);
	PrintHelloWorld();

	int result = MultiplyBy(3, 5);
	PrintNumber(result);
}