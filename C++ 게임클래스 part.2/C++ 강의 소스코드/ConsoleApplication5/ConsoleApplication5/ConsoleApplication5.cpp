// ConsoleApplication5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


/*
숫자 야구 게임 : 1 ~ 9 까지의 숫자 중 랜덤한 숫자 3개가 선택이 되고 그 숫자 3개를 맞추는 게임
컴퓨터가 임의로 3개의 숫자를 순차적으로 선택을 한다. (중복x) ex) 6 2 3

- 반복 -
숫자를 3개를 순차적으로 고른다. ex) 2 0 3 => 볼 아웃 스트라이크
스트라이크 : 1
볼 : 1
아웃 : 1
- 반복 -
*/

int main()
{
	srand(time(NULL));
	rand();

	int nRand1, nRand2, nRand3;
	int nUser1, nUser2, nUser3;
	int nStrike, nBall, nOut;

	int nCount = 0;
	bool bGame = true;

	while (bGame)	// 유저의 선택에 의한 반복 (게임 반복)
	{
		// 게임 데이터 초기화
		nRand1 = rand() % 9 + 1;

		while (true)
		{
			nRand2 = rand() % 9 + 1;
			
			if (nRand2 != nRand1)
				break;
		}

		while (true)
		{
			nRand3 = rand() % 9 + 1;

			if (nRand3 != nRand1 && nRand3 != nRand2)
				break;
		}

		nStrike = 0;

		// 게임 진행
		while (nStrike < 3) // 게임 클리어 조건에 의한 반복
		{
			system("cls");

			nCount++;

			//cout << nRand1 << nRand2 << nRand3 << endl;

			cout << "첫번째 숫자를 고르시오. (1 ~ 9) : ";
			cin >> nUser1;
			cout << "두번째 숫자를 고르시오. (1 ~ 9) : ";
			cin >> nUser2;
			cout << "세번째 숫자를 고르시오. (1 ~ 9) : ";
			cin >> nUser3;

			nStrike = nBall = nOut = 0;

			if (nUser1 == nRand1)
				nStrike++;
			else if (nUser1 == nRand2 || nUser1 == nRand3)
				nBall++;
			else
				nOut++;

			if (nUser2 == nRand2)
				nStrike++;
			else if (nUser2 == nRand1 || nUser2 == nRand3)
				nBall++;
			else
				nOut++;

			if (nUser3 == nRand3)
				nStrike++;
			else if (nUser3 == nRand1 || nUser3 == nRand2)
				nBall++;
			else
				nOut++;

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

