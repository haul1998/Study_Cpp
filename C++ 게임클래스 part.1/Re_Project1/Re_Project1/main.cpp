#include "stdafx.h"

int nCard[12];

void suffle()
{
	for (int i = 0; i < 12; i++)
	{
		nCard[i] = i + 1;
	}

	for (int i = 0; i < 100; i++)
	{
		int nSrc = rand() % 12;
		int nDest = rand() % 12;

		int Temp = nCard[nSrc];
		nCard[nSrc] = nCard[nDest];
		nCard[nDest] = Temp;
	}
}

int main()
{
	srand(time(NULL)); // random에 시드 값을 넣어주는거다. 매번 srand를 할 때마다 시드 값이 바뀐다. time값이 항상 다르기때문이다.

	int nRand1 = nCard[0], nRand2 = nCard[1], nRand3 = nCard[2];
	int nSelect;
	int nMoney = 1000;
	int nBetMoney = 0;
	int nAddBet = 0;


	bool bGame = true;
	bool bRule = true;
	bool bYN = true;

	while (true)
	{
		while (bGame)
		{
			suffle();
			bYN = true;

			nBetMoney = 100;
			while (nMoney > 50 && bRule)
			{
				bYN = true;

				system("cls");
				cout << "=================================================" << endl;
				cout << "남은 금액      : " << nMoney << endl;
				cout << "배팅 금액      : " << nBetMoney << endl;
				cout << "오픈 카드      : " << nCard[0] << " " << nCard[1] << endl;
				cout << "내 카드        : ?" << endl;
				cout << "추가 배팅 카드 : ";
				for (int i = 0; i < nAddBet; i++)
				{
					cout << nCard[i + 3] << " ";
				}
				cout << endl;
				cout << "0.포기, 1.승부, 2.추가 배팅 : ";
				cin >> nSelect;
				cout << "=================================================" << endl;
				if (nSelect == 0 || nSelect == 1)
				{
					cout << "내 카드        : " << nCard[2] << endl;
				}
				switch (nSelect)
				{
					case 0:
					{
						cout << "기권" << endl;
						nMoney = nMoney - nBetMoney + 50;
					}
					break;
					case 1:
					{
						if (nCard[2] > nCard[0] && nCard[2] < nCard[1] || nCard[2] > nCard[1] && nCard[2] < nCard[0])
						{
							cout << "승리" << endl;
							nMoney = nMoney + (nBetMoney * 2);
						}
						else
						{
							cout << "패배" << endl;
							nMoney = nMoney - nBetMoney;
						}
					}
					break;
					case 2:
					{
						if (nAddBet < 3 && nMoney - nBetMoney >= 100)
						{
							cout << "추가 배팅" << endl;
							nBetMoney = nBetMoney + 100;
							nAddBet++;
						}
						else
						{
							cout << "더 이상 추가 배팅할 수 없습니다." << endl;
						}
					}
					break;
					default:
					{
						cout << "잘못입력했습니다." << endl;
					}
					break;
				}
				cout << "=================================================" << endl;
				system("pause");

				if (nMoney < 50)
				{
					cout << "돈이 부족합니다." << endl;
					cout << "게임을 종료합니다." << endl;
				}

				if (nSelect == 0 || nSelect == 1)
				{
					nAddBet = 0;
					bGame = false;
					nBetMoney = 100;
					system("cls");
					cout << "=================================================" << endl;
					cout << "게임을 이어 하시겠습니까? (1.예, 2. 아니요) : ";
					cin >> nSelect;
					switch (nSelect)
					{
					case 1:
					{
						cout << "게임을 이어합니다." << endl;
						bGame = true;
					}
					break;
					case 2:
					{
						cout << "게임을 종료합니다." << endl;
						bRule = false;
						bGame = false;
					}
					break;
					default:
					{
						cout << "잘못 입력했습니다.." << endl;
					}
					break;
					}
					cout << "=================================================" << endl;
					system("pause");
				}
			}

			while (bYN)
			{
				system("cls");
				cout << "=================================================" << endl;
				cout << "게임을 다시 하시겠습니까? (1.예 , 2.아니요) : ";
				cin >> nSelect;
				switch (nSelect)
				{
				case 1:
				{
					cout << "게임을 재시작합니다." << endl;
					bGame = true;
					bRule = true;
					bYN = false;
				}
				break;
				case 2:
				{
					cout << "게임을 종료합니다." << endl;
					bYN = false;
					bGame = false;
				}
				break;
				default:
				{
					cout << "잘못 입력하였습니다.";
				}
				break;
				cout << "=================================================" << endl;
				}
				system("pause");
			}
			break;
		}
		break;
	}
	return 0;
}