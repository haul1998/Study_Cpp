#include <iostream>
using namespace std;

// cout : 출력 명령어
// cin : 입력 명령어
// endl : 줄바꿈 명령어

/*

10진법
0 ~ 9의 숫자 표현되는 데이터 : 예) 9, 26

2진법
0과 1 두개의 숫자로 표현되는 데이터 : 예) 0, 1

10진법 : 2진법
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101

1bit -> 0
1byte == 8bit : 00000000 ~ 111111111 = 2^8 = 0 ~ 255
*/

/*
데이터 자료형
bool	: 1byte 문자형 - 참과 거짓을 표현한다. true(1), false(0)
char	: 1byte 문자형 - 문자 하나를 표현 예) a, b, c
  - 영어 문자는 1byte지만 한글 문자는 2byte라 한글은 불가능
short	: 2byte 정수형 (음수, 0, 양수)
		- 요즘은 용량이 넉넉해서 잘 사용되지 않음 / short가 int에 비해 표현할 수 있는 제한이 적기 때문
int		: 4byte 정수형
float	: 4byte 실수형 (소수점을 포함하는 숫자)
double	: 8byte 실수형
*/

/*
연산자
대입 연산자 : =
비교 연산자 : == (수학에서의 =)
ex ) a = 10 은 a에 10을 넣는다

산술 연산자 : + - * /
*/

void main()
{
	// 헝가리안 표기법 : 변수명 앞에 데이터 타입을 표기해주는 방식, 변수명이 어떻게 만들자는 약속, 변수 이름을 지을 때 용도에 따라서 짓는법
	// ex) isPlaying, bPlay
	
	// 변수 선언
	bool isPlaying;
	bool bPlay;
	char chLetter;
	short shArmor;
	int nAttack; // int는 주로 n으로 시작하는게 많다, i는 반복문에 주로 쓰이기에 클라이언트에서는 n을 주로 쓴다 / 서버쪽에서는 i로 쓰는편
	float fSpeed;
	double dPower;

	isPlaying = true;
	bPlay = false;

	chLetter = 'a'; // char의 경우 작은 따옴표로 해야함
	shArmor = 10;
	nAttack = 20;
	fSpeed = 3.0f; // 뒤에 f가 붙으면 float, 붙지 않으면 double
	dPower = 4.0;

	cout << "chLetter : " << chLetter << endl;
	cout << "nAttack : " << nAttack << endl;
	cout << "fSpeed : " << fSpeed << endl;
	cout << shArmor * nAttack << endl; // short와 int는 산술 연산자 사용이 가능하다

	cout << "파워를 입력하세요 : ";
	cin >> dPower;

	cout << "입력하신 파워는 " << dPower << "입니다." << endl;

	system("pause");	
}