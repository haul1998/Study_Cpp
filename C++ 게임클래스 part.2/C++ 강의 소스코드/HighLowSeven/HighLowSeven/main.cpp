// HighLowSeven.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

enum E_SHAPE { E_SPADE, E_DIA, E_HEART, E_CLOVER, E_MAX };
enum E_SELECT { E_QUIT, E_HIGH, E_LOW, E_SEVEN };

// 하이로우세븐
// 52장의 포커카드를 사용 합니다.
// 게임 시작 후 5장의 카드를 오픈 해서 보여줍니다.
// 그리고 그 다음 1장이 7보다 크다, 작다, 같다를 맞추는 게임

struct tagCard
{
	char*		szShape;
	int			nNumber;
};

void InitCards(tagCard* cards);			// 전체 카드 초기화
void Suffle(tagCard* cards);			// 카드 섞기
void Print(tagCard* cards);				// 전체 카드 출력
void Print(tagCard* cards, int index);	// 플레이 카드 출력

void Play(tagCard* cards, int* money, int* index, bool* playing);
int Betting(int money);

int main()
{
	srand(time(NULL));
	rand();

	tagCard stCards[52];
	bool	isPlaying = true;
	int		nMyMoney = 10000;
	int		nCurrIndex = 5;

	InitCards(stCards);
	Suffle(stCards);
	//Print(stCards);

	system("pause");

	while (isPlaying)
	{
		system("cls");

		Print(stCards, nCurrIndex);

		if (nMyMoney < 100)
		{
			// 게임 강제 종료
			cout << "거지가 되었습니다. 게임장에서 나갑니다." << endl;
			isPlaying = false;
		}
		else if (nCurrIndex > 42)
		{
			// 새 카드로 교체 (다시 섞기)
			Suffle(stCards);
			nCurrIndex = 5;

			cout << "새 카드로 게임을 계속 합니다." << endl;

			system("pause");
		}
		else
		{
			// 플레이
			Play(stCards, &nMyMoney, &nCurrIndex, &isPlaying);
			Sleep(2000);
		}
	}

	system("pause");

    return 0;
}

void InitCards(tagCard* cards)
{
	for (E_SHAPE i = E_SPADE; i < E_MAX; i = (E_SHAPE)(i + 1))
	{
		for (int j = 0; j < 13; j++)
		{
			switch (i)
			{
			case E_SPADE:
				cards[i * 13 + j].szShape = (char*)"♠";
				break;
			case E_DIA:
				cards[i * 13 + j].szShape = (char*)"◆";
				break;
			case E_HEART:
				cards[i * 13 + j].szShape = (char*)"♥";
				break;
			case E_CLOVER:
				cards[i * 13 + j].szShape = (char*)"♣";
				break;
			}

			cards[i * 13 + j].nNumber = j + 1;
		}
	}
}

void Suffle(tagCard* cards)
{
	for (int i = 0; i < 1000; i++)
	{
		int nSrc = rand() % 52;
		int nDest = rand() % 52;

		tagCard stTemp = cards[nSrc];
		cards[nSrc] = cards[nDest];
		cards[nDest] = stTemp;
	}
}

void Print(tagCard* cards)
{
	for (int i = 0; i < 52; i++)
	{
		switch (cards[i].nNumber)
		{
		case 1:
			cout << cards[i].szShape << "A" << "\t";
			break;
		case 11:
			cout << cards[i].szShape << "J" << "\t";
			break;
		case 12:
			cout << cards[i].szShape << "Q" << "\t";
			break;
		case 13:
			cout << cards[i].szShape << "K" << "\t";
			break;
		default:
			cout << cards[i].szShape << cards[i].nNumber << "\t";
			break;
		}

		if (i % 13 == 12)
			cout << endl;
	}
}

void Print(tagCard* cards, int index)
{
	for (int i = index - 5; i < index; i++)
	{
		cout << cards[i].szShape << cards[i].nNumber << "\t";
	}
	cout << "\t ( ? )" << endl;
}

void Play(tagCard* cards, int* money, int* index, bool* playing)
{
	int			nSelect;
	E_SELECT	eSelect;
	int			nBet;

	cout << "현재 금액 : " << *money << endl;
	cout << "1.하이 2.로우 3.세븐 (0.종료) : ";
	cin >> nSelect;

	eSelect = (E_SELECT)nSelect;

	switch (eSelect)
	{
	case E_QUIT:
		cout << "게임을 종료 합니다." << endl;
		*playing = false;
		break;
	case E_HIGH:
		nBet = Betting(*money);	// 금액 베팅

		if (cards[*index].nNumber > 7)	// 승
		{
			cout << "베팅 성공! : ";
			*money += nBet;
		}
		else // 패
		{
			cout << "베팅 실패! : ";
			*money -= nBet;
		}

		cout << cards[*index].szShape << cards[*index].nNumber << endl;
		break;
	case E_LOW:
		nBet = Betting(*money);	// 금액 베팅

		if (cards[*index].nNumber < 7)	// 승
		{
			cout << "베팅 성공! : ";
			*money += nBet;
		}
		else // 패
		{
			cout << "베팅 실패! : ";
			*money -= nBet;
		}

		cout << cards[*index].szShape << cards[*index].nNumber << endl;
		break;
	case E_SEVEN:
		nBet = Betting(*money);	// 금액 베팅

		if (cards[*index].nNumber == 7)	// 승
		{
			cout << "베팅 성공! : ";
			*money += nBet * 2;
		}
		else // 패
		{
			cout << "베팅 실패! : ";
			*money -= nBet;
		}

		cout << cards[*index].szShape << cards[*index].nNumber << endl;
		break;
	}

	*index += 6;
}

int Betting(int money)
{
	int nBet = 0;

	while (nBet < 100 || nBet > money)
	{
		cout << "금액을 배팅하시오.(100 ~ 보유금액) : ";
		cin >> nBet;
	}

	return nBet;
}