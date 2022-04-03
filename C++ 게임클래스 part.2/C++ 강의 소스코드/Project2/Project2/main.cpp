#include <iostream>		// C++ 표준 라이브러리

using namespace std;

// 기본 명령어
// cout, cin

/* 자료형
1Byte = 8bit

bool : 1바이트 불형 - 참과 거짓을 표현 - true, false - 1, 0
char : 1바이트 문자형 - 'a' 'b'
short : 2바이트 정수형(음수, 0, 양수)
int : 4바이트 정수형
float : 4바이트 실수형(소수점)
double : 8바이트 실수형
*/

/* 연산자
대입 연산자 =
수학 A = 10 => A는 10과 같다.
프로그래밍 A = 10 => A에 10을 대입한다.

산술 연산자 + - * /
*/

void main()
{
	//  헝가리안 표기법 변수 선언
	bool isTest, bTest;
	char chLetter;
	int nData, nData2, nData3;
	float fData;
	double dData;

	//isTest = true;
	isTest = 10;
	bTest = false;
	// bTest = 0;

	chLetter = 'a';

	nData = 10;

	fData = 0.5f;

	dData = 0.5;

	cout << "isTest " << isTest << endl;
	cout << "chLetter " << chLetter << endl;
	cout << "nData " << nData << endl;
	cout << "fData " << fData << endl;
	cout << "dData " << dData << endl;
	cout << "==============================" << endl;

	nData = 10;
	nData2 = 3;
	nData3 = nData + nData2;
	cout << "nData + nData2 = " << nData3 << endl;
	cout << "nData * nData2 = " << nData * nData2 << endl;
	cout << "==============================" << endl;

	cout << "정수를 입력 하세요 : ";
	cin >> nData3;
	cout << nData3 << endl;

	system("pause");
}