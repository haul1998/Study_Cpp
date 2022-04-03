// 하이로우세븐 규칙

// 52장의 포커카드를 사용
// 게임 시작 시 5장의 카드를 오픈해서 보여준다.
// 그 다음 1장이 7보다 크다 작다 같다를 맞추는 게임

// 크다 혹은 작다를 맞춘 경우 베팅한 금액만큼 추가로 번다.
// 7인걸 맞춘 경우 베팅한 금액의 1.5배를 번다.


#include "stdafx.h"

enum E_SHAPE
{
    E_SPADE, E_DIA, E_HEART, E_CLOVER, E_MAX
};
enum E_SELECT
{
    E_QUIT, E_HIGH, E_LOW, E_SEVEN
};

struct tagCard      // 카드의 모양 설정 : 하트 다이아 스페이드 클로버
{
    char*   szShape;
    int     nNumber;
};

void InitCards(tagCard* cards);         // 전체 카드 초기화
void Suffle(tagCard* cards);            // 카드 셔플
void Print(tagCard* cards);             // 전체 카드 출력
void PrintPlay(tagCard* cards, int index);  // 플레이 카드 출력
void Play(tagCard* cards, int* money, int* index, bool* playing);
int Betting(int money);

int main()
{
    srand(time(NULL));
    
    rand();

    tagCard stCards[52];
    bool isPlaying = true;
    int nMyMoney = 10000;
    int nCurrIndex = 5;

    InitCards(stCards);
    Suffle(stCards);
    //Print(stCards);

    //system("pause");
    
    while (isPlaying)
    {
        system("cls");
        
        PrintPlay(stCards, nCurrIndex);
        system("pause");

        if (nMyMoney < 100)
        {
            // 게임 강제 종료
            cout << "소지금이 부족합니다. 게임장에서 나갑니다." << endl;
        }
        else if (nCurrIndex > 42)   // 새 카드로 교체 (다시 섞기)
        {
            // 새 카드로 교체 (다시 섞기)
            Suffle(stCards);
            nCurrIndex = 5;

            cout << "새 카드로 게임을 진행합니다." << endl;
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
    for (E_SHAPE i = E_SPADE; i < E_MAX; i = (E_SHAPE)(i + 1)) // enum문으로 만들어서 enum문에 대한 증감은 강제 형 변환을 사용해야한다.
    {
        for (int j = 0; j < 13; j++)
        {
            switch (i)
            {
            case E_SPADE:
            {
                cards[i * 13 + j].szShape = (char*)"♠";    // " "로 입력한건 문자열 상수값이라 형변환을 해줘야한다.
            }
                break;
            case E_DIA:
            {
                cards[i * 13 + j].szShape = (char*)"◆";
            }
                break;
            case E_HEART:
            {
                cards[i * 13 + j].szShape = (char*)"♥";
            }
                break;
            case E_CLOVER:
            {
                cards[i * 13 + j].szShape = (char*)"♣";
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

void Print(tagCard* cards)
{
    for (int i = 0; i < 52; i++)
    {
        switch (cards[i].nNumber)
        {
            case 1:
            {
                cout << cards[i].szShape << "A" << "\t";
            }
            break;
            case 11:
            {
                cout << cards[i].szShape << "J" << "\t";
            }
            break;
            case 12:
            {
                cout << cards[i].szShape << "Q" << "\t";
            }
            break;
            case 13:
            {
                cout << cards[i].szShape << "K" << "\t";
            }
            break;
            default:
            {
                cout << cards[i].szShape << cards[i].nNumber << "\t";
            }
            break;
        }
        if (i % 13 == 12)
        {
            cout << endl;
        }
    }
}

void PrintPlay(tagCard* cards, int index)
{
    for (int i = index - 5; i < 5; i++)
    {
        cout << cards[i].szShape << cards[i].nNumber << "\t";
    }
    cout << "\t ( ? )" << endl;
}

void Play(tagCard* cards, int* money, int* index, bool* playing)
{
    int nSelect;
    E_SELECT eSelect;
    int nBet = 0;

    cout << "현재 금액 : " << *money << endl;
    cout << "0.종료 1.하이 2.로우 3.세븐 : ";
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
            nBet = Betting(*money);     // 금액 배팅

            if (cards[*index].nNumber > 7)
            {
                cout << "베팅 성공" << endl;
                *money += nBet;
            }
            else                        // 패배
            {
                cout << "베팅 실패" << endl;
                *money -= nBet;
            }
            cout << "카드 : " << cards[*index].szShape << cards[*index].nNumber << endl;
            break;
        case E_LOW:
            if (cards[*index].nNumber < 7)
            {
                cout << "베팅 성공" << endl;
                *money += nBet;
            }
            else                        // 패배
            {
                cout << "베팅 실패" << endl;
                *money -= nBet;
            }
            cout << "카드 : " << cards[*index].szShape << cards[*index].nNumber << endl;
            break;
        case E_SEVEN:
        {
            if (cards[*index].nNumber == 7)
            {
                cout << "베팅 성공" << endl;
                *money += nBet * 1.5;
            }
            else
            {
                cout << "베팅 실패" << endl;
                *money -= nBet;
            }
        }
        cout << "카드 : " << cards[*index].szShape << cards[*index].nNumber << endl;
        break;
        }
    }
    *index += 6;
}
int Betting(int money)
{
    int nBet = 0;

    while (nBet < 100 || nBet > money)
    {
        cout << "금액을 배팅하세요 (100 ~ 보유금액) : ";
        cin >> nBet;
    }
    return nBet;
}