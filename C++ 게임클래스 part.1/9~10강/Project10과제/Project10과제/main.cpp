#include "stdafx.h"

int main()
{
    srand(time(NULL));
    rand();

    int nPlayerMoney = 1000;
    int nCard[12];          
    int nCount;             
    int nSelect;            
    bool bGame = true;

    while (bGame)
    {
        while (nPlayerMoney > 0)
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
            /*
            for (int i = 0; i < 12; i++) // 카드 셔플 확인용
            {
                cout << nCard[i] << endl;
            }
            system("pause");
            */

            nCount = 0;
            cout << "=======================================" << endl;
            cout << "       승패에 따라 배팅 100원을" << endl;
            cout << "        차감 혹은 증가 합니다." << endl;
            cout << "        기권 시 50원 차감합니다." << endl;
            cout << "=======================================" << endl;
            cout << "현재 금액      : " << nPlayerMoney << "원" << endl;
            cout << "승부 카드      : " << "? ? ?" << endl;
            cout << "내 카드        : ?" << endl;
            cout << "오픈 카드      : ";

            for (int i = 0; i <9; i++)
            {
                cout << nCard[i + 3] << " ";
            }

            cout << endl;
            cout << "=======================================" << endl;
            cout <<  "1.카드 공개, 2.포기 : ";
            cin >> nSelect;

            cout << "=======================================" << endl;
            cout << "승부 카드      : " << nCard[0] << " " << nCard[1] << endl;
            cout << "내 카드        : " << nCard[2] << endl;
            cout << "=======================================" << endl;

            if (nSelect == 1)
            {
                if (nCard[2] > nCard[0] && nCard[2] < nCard[1] || nCard[2] > nCard[1] && nCard[2] < nCard[0])
                {
                    cout << "승리 + 100원" << endl;
                    nPlayerMoney += 100;
                }
                else
                {
                    cout << "패배 - 100원" << endl;
                    nPlayerMoney -= 100;
                }
            }
            else if (nSelect == 2)
            {
                cout << "기권 - 50원" << endl;
                nPlayerMoney -= 50;
            }
            else
            {
                cout << "         잘못 입력하였습니다." << endl;
                cout << "       새 게임을 재시작 합니다." << endl;
                cout << "=======================================" << endl;
            }
            system("pause");
            system("cls");

        }
        char chYN;
        cout << "=======================================" << endl;
        cout << "    게임을 다시 시작하시겠습니까?" << endl;
        cout << "=======================================" << endl;
        cout << "(y , n) : ";
        cin >> chYN;

        if (chYN == 'y' || chYN == 'Y')
        {
            cout << "=======================================" << endl;
            cout << "       게임을 재시작 합니다." << endl;
            cout << "=======================================" << endl;
            bGame = true;
            system("pause");
            system("cls");
            nPlayerMoney = 1000;
        }
        else if (chYN == 'n' || chYN == 'N')
        {
            cout << "=======================================" << endl;
            cout << "         게임을 종료합니다." << endl;
            cout << "=======================================" << endl;
            bGame = false;
        }
        else
        {
            cout << "=======================================" << endl;
            cout << "         잘못 입력하였습니다" << endl;
            cout << "         게임을 종료합니다." << endl;
            cout << "=======================================" << endl;
            bGame = false;
        }
    }
    system("pause");
    return 0;
}