// ConsoleApplication10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int nCards[52];

int Add(int a, int b)
{
	return a + b;
}

int Subtract(int a, int b)
{
	return a - b;
}

int DamageToMonster(int base, int weapon, int monArmor)
{
	int addDamage = 10;

	return base + weapon - monArmor + addDamage;
}

void Suffle()
{
	int nSrc = rand() % 52;
	int nDest = rand() % 52;

	int nTemp = nCards[nSrc];
	nCards[nSrc] = nCards[nDest];
	nCards[nDest] = nTemp;
}

// 메인 함수
int main()
{
	srand(time(NULL));
	rand();

	int nA = 10, nB = 5;

	cout << Add(nA, nB) << endl;
	cout << nA + nB << endl;
	cout << Subtract(6, 3) << endl;

	cout << DamageToMonster(5, 10, 3) << endl;

	// == 플레이 == 
	Suffle();

	// == 새 카드가 필요하다 ==
	Suffle();

	// == 새 카드가 필요하다 ==
	Suffle();

	// == 새 카드가 필요하다 ==
	Suffle();

	system("pause");

    return 0;
}