#include "stdafx.h"

enum E_SHAPE
{
    E_HEART, E_DIA, E_SPADE, E_CLOVER, EMAX
};
enum E_SELECT
{
    E_QUIT, E_HIGH, E_LOW, E_SEVEN, E_MAX
};
struct tagCard
{
    char* chShape;
    int nNumber;
};

void Reset(tagCard* cards);
void Suffle(tagCard* cards);
void Print(tagCard* cards, int index);
void Play(tagCard* cards, int* money, int* index, bool* playing);
int Betting(int money);

int main()
{
    srand(time(NULL));
    rand();

    tagCard stCards[52];

    bool isPlaying = true;
    int nMoney = 10000;
    int nIndex = 5;

    Reset(stCards);
    Suffle(stCards);

    while (isPlaying)
    {
        system("cls");
        Print(stCards, nIndex);

        if (nMoney < 100)
        {
            cout << "금액 부족으로 게임이 종료됩니다." << endl;
            isPlaying = false;
        }
        else if (nIndex > 42)
        {
            Suffle(stCards);
            nIndex = 5;
            cout << "새 카드로 게임을 진행합니다." << endl;
            system("pause");
        }
        else
        {
            Play(stCards, &nMoney, &nIndex, &isPlaying);
            Sleep(2000);
        }
    }
    system("pause");
    return 0;
}

void Reset(tagCard* cards)
{
    for (E_SHAPE i = E_HEART; i < E_MAX; i = (E_SHAPE)(i + 1))
    {
        for (int j = 0; j < 13; j++)
        {
            switch (i)
            {
            case E_HEART:
            {
                cards[i * 13 + j].chShape = (char*)"♥";
            }
            break;
            case E_DIA:
            {
                cards[i * 13 + j].chShape = (char*)"◆";
            }
            break;
            case E_SPADE:
            {
                cards[i * 13 + j].chShape = (char*)"♠";
            }
            break;
            case E_CLOVER:
            {
                cards[i * 13 + j].chShape = (char*)"♣";
            }
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

        tagCard Temp = cards[nSrc];
        cards[nSrc] = cards[nDest];
        cards[nDest] = Temp;

    }
}

void Print(tagCard* cards, int index)
{
    for (int i = index - 5; i < index; i++)
    {
        cout << cards[i].chShape << cards[i].nNumber << "\t";
    }
    cout << "\t(?)" << endl;
}

void Play(tagCard* cards, int* money, int* index, bool* playing)
{
    int nSelect;
    E_SELECT eSelect;
    int nBet;

    cout << "현재 금액 : " << *money << endl;
    cout << "0.포기 1.하이 2.로우 3.세븐 : ";
    cin >> nSelect;

    eSelect = (E_SELECT)nSelect;

    switch (eSelect)
    {
    case E_QUIT:
    {
        cout << "게임을 종료합니다." << endl;
        *playing = false;
    }
    break;
    case E_HIGH:
    {
        nBet = Betting(*money);

        if (cards[*index].nNumber > 7)
        {
            cout << "베팅 성공" << endl;
            *money += nBet;
        }
        else
        {
            cout << "배팅 실패" << endl;
            *money -= nBet;
        }
    }
    break;
    case E_LOW:
    {
        nBet = Betting(*money);

        if (cards[*index].nNumber < 7)
        {
            cout << "베팅 성공" << endl;
            *money += nBet;
        }
        else
        {
            cout << "배팅 실패" << endl;
            *money -= nBet;
        }
    }
    break;
    case E_SEVEN:
    {
        nBet = Betting(*money);

        if (cards[*index].nNumber == 7)
        {
            cout << "베팅 성공" << endl;
            *money += nBet * 1.5;
        }
        else
        {
            cout << "배팅 실패" << endl;
            *money -= nBet;
        }
    }
    break;
    }
    cout << cards[*index].chShape << cards[*index].nNumber << endl;

    *index += 6;

}
int Betting(int money)
{
    int nBet = 0;

    while (nBet < 100 || nBet > money)
    {
        cout << "금액 배팅 (100 ~ " << money << ") : ";
        cin >> nBet;
    }
    return nBet;
}