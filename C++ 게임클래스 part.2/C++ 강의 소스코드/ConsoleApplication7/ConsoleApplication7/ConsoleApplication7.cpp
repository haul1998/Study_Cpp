// ConsoleApplication7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

/*
카드 : 1 ~ 12까지의 숫자 카드
1. 카드 2장이 랜덤 하게 선택 되고 플레이어에게 보여진다.
1.5 카드 1장은 선택이 되고 경기 종료까지 오픈되지 않는다.
ex) 7 ~ 10
2. 기본 베팅 200
3. 게임 포기 : 100 회수, 스탑 : 승부, 추가 베팅 : 따블-카드 추가 오픈
 => 승부 : 숨겨진 카드가 위에 오픈 된 두 숫자 사이의 카드라면 승리 ex) 숨겨진 카드 9 == 승리
 => 추가 베팅 : 선택 되지 않은 카드 중에 한장이 오픈 된다.
*/

int main()
{
	srand(time(NULL));
	rand();

	// 플레이어의 총 금액, 베팅 금액, 카드 12장 (배열), 베팅 횟수, 게임 지속
	// 배열의 0, 1 오픈 카드 2 승부 카드 4 5 6 추가 베팅시 오픈 카드

	int nMoney = 200;
	int nBet;
	int nAddBet;
	int nCards[12];
	bool isPlaying = true;

	while (isPlaying)
	{
		for (int i = 1; i <= 12; i++)
			nCards[i - 1] = i;

		for (int i = 0; i < 100; i++)
		{
			int nSrc = rand() % 12;
			int nDest = rand() % 12;

			int nTemp = nCards[nSrc];
			nCards[nSrc] = nCards[nDest];
			nCards[nDest] = nTemp;
		}

		nBet = 200;
		nAddBet = 1;

		if (nCards[0] > nCards[1])
		{
			int nTemp = nCards[0];
			nCards[0] = nCards[1];
			nCards[1] = nTemp;
		}

		while (true)
		{
			system("cls");

			cout << "현재 보유 금액 : " << nMoney << endl;
			cout << "==============================" << endl;
			cout << "현재 베팅 금액 : " << nBet * nAddBet << endl;
			cout << "오픈 카드 : " << nCards[0] << " ~ " << nCards[1] << endl;
			cout << "승부 카드 : ?" << endl;

			cout << "추가 오픈 :\t";

			int nIndex = 0;
			for (int i = 2; i <= nAddBet; i *= 2)
			{
				cout << nCards[3 + (nIndex++)] << "\t";
			}

			for (int i = nAddBet; i < 8; i *= 2)
				cout << "?\t";

			cout << endl;

			int nSelect;
			cout << "1.포기, 2.승부, 3.추가베팅 : ";
			cin >> nSelect;

			if (nSelect == 1)
			{
				cout << "게임 포기!!" << endl;
				cout << "승부 카드 : " << nCards[2] << endl;

				nMoney -= nBet * nAddBet / 2;
				break;
			}
			else if (nSelect == 2)
			{
				cout << "승부~!!!" << endl;
				cout << "승부 카드 : " << nCards[2] << endl;

				if (nCards[2] > nCards[0] && nCards[2] < nCards[1])
				{
					cout << "플레이어 승리!!" << endl;
					nMoney += nBet * nAddBet;
				}
				else
				{
					cout << "플레이어 패배!!" << endl;
					nMoney -= nBet * nAddBet;
				}
				break;
			}
			else if (nSelect == 3)
			{
				if (nMoney < nBet * nAddBet * 2)
					cout << "보유 금액이 부족 합니다." << endl;
				else
					nAddBet *= 2;
			}
			else
			{
				cout << "선택 범위 안에서 숫자를 고르세요." << endl;
			}
		}

		if (nMoney < 200)
		{
			cout << "더 이상 플레이를 할 금액이 없습니다." << endl
				<< "게임을 종료 합니다." << endl;

			isPlaying = false;
		}
		else
		{
			char chYN;
			cout << "다음 게임 (y, n)";
			cin >> chYN;

			if (chYN == 'n')
				isPlaying = false;
		}
	}

	system("pause");

    return 0;
}

