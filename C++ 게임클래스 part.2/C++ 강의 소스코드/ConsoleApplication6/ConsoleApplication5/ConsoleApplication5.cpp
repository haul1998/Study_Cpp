// ConsoleApplication5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

// 배열 : 순차적인 공간을 할당해서 데이터를 저장하는 방식

int main()
{
	srand(time(NULL));
	rand();

	int nRand[9];
	int nUser[3];
	int nStrike, nBall, nOut;

	int nCount = 0;
	bool bGame = true;

	while (bGame)	// 유저의 선택에 의한 반복 (게임 반복)
	{
		for (int i = 0; i < 9; i++)
			nRand[i] = i + 1;

		for (int i = 0; i < 100; i++)
		{
			int nSrc = rand() % 9;
			int nDest = rand() % 9;

			int nTemp = nRand[nSrc];
			nRand[nSrc] = nRand[nDest];
			nRand[nDest] = nTemp;
		}

		nStrike = 0;

		// 게임 진행
		while (nStrike < 3) // 게임 클리어 조건에 의한 반복
		{
			system("cls");

			nCount++;

			//cout << nRand[0] << nRand[1] << nRand[2] << endl;

			cout << "첫번째 숫자를 고르시오. (1 ~ 9) : ";
			cin >> nUser[0];
			cout << "두번째 숫자를 고르시오. (1 ~ 9) : ";
			cin >> nUser[1];
			cout << "세번째 숫자를 고르시오. (1 ~ 9) : ";
			cin >> nUser[2];

			nStrike = nBall = nOut = 0;

			for (int i = 0; i < 3; i++)
			{
				if (nUser[i] == nRand[i])
					nStrike++;
				else if (nUser[i] == nRand[(i + 1) % 3] ||
					nUser[i] == nRand[(i + 2) % 3])
					nBall++;
				else
					nOut++;
			}

			cout << "스트라이크 : " << nStrike << endl;
			cout << "       볼 : " << nBall << endl;
			cout << "     아웃 : " << nOut << endl;

			system("pause");
		}
		cout << "총 도전 횟수 : " << nCount << endl;

		// 게임 클리어 후 새 게임, 게임 종료 선택
		char chYN;
		cout << "새 게임(y, n) ";
		cin >> chYN;

		if (chYN == 'n')
			bGame = false;
	}

	system("pause");

    return 0;
}

