// 실제 숫자 야구 게임을 반영하여 시도 횟수 10회를 넘기면 게임이 끝나게 제작

#include "stdafx.h"

int main()
{
	srand(time(NULL));
	rand();

	int nRand1, nRand2, nRand3;
	int nPlay1, nPlay2, nPlay3;
	int strike = 0;
	int ball = 0;
	int out = 0;
	int nCount = 0;
	bool bGame = true;

	while (bGame)
	{
		nRand1 = rand() % 9 + 1; // 1번 번호 뽑기
		while (true)
		{
			nRand2 = rand() % 9 + 1; // 2번 번호 뽑기
			if (nRand2 != nRand1)
				break;
		}
		while (true)
		{
			nRand3 = rand() % 9 + 1;
			if (nRand3 != nRand1 && nRand3 != nRand2) // 3번 번호뽑기
				break;
		}

		while (strike < 3 || nCount < 11) // 클리어 조건
		{
			strike, ball, out = 0;
			cout << "정답 : " << nRand1 << nRand2 << nRand3 << endl;
			cout << "첫번째 숫자를 입력하세요 : ";
			cin >> nPlay1;
			cout << "두번째 숫자를 입력하세요 : ";
			cin >> nPlay2;
			cout << "세번째 숫자를 입력하세요 : ";
			cin >> nPlay3;

			if (nPlay1 == nRand1) // 1번째 스트라이크 체크
			{
				strike++;
			}
			else if (nPlay1 == nRand2 || nPlay1 == nRand3) // 1번째 볼 체크
			{
				ball++;
			}
			else // 1번째 아웃 체크
			{
				out++;
			}

			if (nPlay2 == nRand2) // 2번째 스트라이크 체크
			{
				strike++;
			}
			else if (nPlay2 == nRand1 || nPlay2 == nRand3) // 2번째 스트라이크 체크
			{
				ball++;
			}
			else // 2번째 아웃 체크
			{
				out++;
			}

			if (nPlay3 == nRand3) // 3번째 스트라이크 체크
			{
				strike++;
			}
			else if (nPlay3 == nRand1 || nPlay3 == nRand2) // 3번째 볼 체크
			{
				ball++;
			}
			else // 3번째 아웃 체크
			{
				out++;
			}
			nCount++;

			cout << "스트라이크 : " << strike << endl;
			cout << "볼         : " << ball << endl;
			cout << "아웃       : " << out << endl;
			cout << "시도 횟수  : " << nCount << endl;
			cout << "================================" << endl;
			
			if (strike == 3)
			{
				cout << "CLEAR" << endl;
				cout << "정답 : " << nRand1 << nRand2 << nRand3 << endl;
				break;
			}
			else if (nCount == 10)
			{
				cout << "FAIL" << endl;
				cout << "정답 : " << nRand1 << nRand2 << nRand3 << endl;
				break;
			}
			system("pause");
		}

		//게임 재진행 여부
		char chYN;
		cout << "================================" << endl;
		cout << "게임을 다시 하시겠습니까?(y , n) : ";
		cin >> chYN;

		if (chYN == 'y' || chYN == 'Y')
		{
			bGame = true;
		}
		else if (chYN == 'n' || chYN == 'N')
		{
			bGame = false;
		}
		else
		{
			cout << "잘못 입력했습니다." << endl;
			bGame = false;
		}
		
	}
	system("pause");
	return 0;
}