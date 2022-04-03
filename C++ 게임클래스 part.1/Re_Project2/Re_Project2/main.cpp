#include "stdafx.h"

int nCard[9];
int nRand[3];
int nPlay[3];

void suffle()
{
	for (int i = 0; i < 9; i++)
	{
		nCard[i] = i + 1;
	}

	for (int i = 0; i < 100; i++)
	{
		int nSrc = rand() % 9;
		int nDest = rand() % 9;

		int Temp = nCard[nSrc];
		nCard[nSrc] = nCard[nDest];
		nCard[nDest] = Temp;
	}
	
	for (int i = 0; i < 3; i++)
	{
		nRand[i] = nCard[i];
;	}
}

int main()
{
	srand(time(NULL));

	int strike = 0, ball = 0, out = 0;
	int nCount = 0;
	int nSelect = 0;
	bool bGame = true;
	bool bSelect = true;

	while (bGame)
	{
		suffle();
		while (strike < 3 || nCount < 11)
		{
			strike = 0, ball = 0, out = 0;
			system("cls");
			cout << "정답 : ";
			for (int i = 0; i < 3; i++)
			{
				cout << nRand[i];
			}
			cout << endl;
			cout << "시도 횟수 : " << nCount << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << i + 1 << "번째 숫자를 입력하세요. : ";
				cin >> nPlay[i];
			}

			for (int i = 0; i < 3; i++)
			{
				if (nPlay[i] == nRand[i])
				{
					strike++;
				}
				else if (nPlay[i] == nRand[i + 1] || nPlay[i] == nRand[i + 2] || nPlay[i] == nRand[i - 1] || nPlay[i] == nRand[i - 2])
				{
					ball++;
				}
				else
				{
					out++;
				}
			}
			nCount++;
			cout << "스트라이크 : " << strike << endl;
			cout << "볼         : " << ball << endl;
			cout << "아웃       : " << out << endl;
			system("pause");

			if (strike == 3 || nCount >= 10)
			{
				if (strike == 3)
				{
					cout << "승리" << endl;
				}
				else if (nCount >= 10)
				{
					cout << "패배" << endl;
				}
				break;
			}
		}
		system("pause");
		system("cls");

		while (bSelect)
		{
			cout << "게임을 다시 진행하시겠습니까?" << endl;
			cout << "1.다시 시작, 2.종료 : ";
			cin >> nSelect;

			switch (nSelect)
			{
				case 1:
				{
					cout << "게임을 재시작합니다." << endl;
					nCount = 0;
					bSelect = false;
				}
				break;
				case 2:
				{
					cout << "게임을 종료합니다." << endl;
					bGame = false;
					bSelect = false;
				}
				break;
				default:
				{
					cout << "잘못입력하셨습니다." << endl;
				}
				break;
			}
		}
		bSelect = true;
	}
	return 0;
}