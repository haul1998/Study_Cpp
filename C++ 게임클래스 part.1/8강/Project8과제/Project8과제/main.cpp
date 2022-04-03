#include "stdafx.h"

int main()
{
    srand(time(NULL));
    rand();

    int nRand[10];
    int nPlay[3];
    int strike = 0;
    int ball = 0;
    int out = 0;
    int nCount;
    bool bGame = true;
    
    while (bGame) // 게임의 틀
    {
        nCount = 0;

        for (int i = 0; i <= 9; i++)
        {
            nRand[i] = i + 11; // 0 ~ 9에 10을 더해서 10 ~ 19로 만들기
            // cout << nRand[i] << endl; // 잘 작동하는지 확인용

        }


        for (int i = 0; i < 100; i++)
        {
            int nSrc = rand() % 10;
            int nDest = rand() % 10;

            int Temp = nRand[nSrc];
            nRand[nSrc] = nRand[nDest];
            nRand[nDest] = Temp;
        }

        while (strike < 3 || nCount < 10) // 스트라이크가 3개 미만이거나 시도 횟수가 10번을 넘기면 게임 끝
        {
            strike = ball = out = 0;
            cout << "정답 : " << nRand[0] << " " << nRand[1] << " " << nRand[2] << endl;
            cout << "첫번째 숫자(10 ~ 19) : ";
            cin >> nPlay[0];
            cout << "두번째 숫자(10 ~ 19) : ";
            cin >> nPlay[1];
            cout << "세번째 숫자(10 ~ 19) : ";
            cin >> nPlay[2];

            if (nPlay[0] == nRand[0])
            {
                strike++;
            }
            else if (nPlay[0] == nRand[1] || nPlay[0] == nRand[2])
            {
                ball++;
            }
            else
            {
                out++;
            }

            if (nPlay[1] == nRand[1])
            {
                strike++;
            }
            else if (nPlay[1] == nRand[0] || nPlay[1] == nRand[2])
            {
                ball++;
            }
            else
            {
                out++;
            }

            if (nPlay[2] == nRand[2])
            {
                strike++;
            }
            else if (nPlay[2] == nRand[0] || nPlay[2] == nRand[1])
            {
                ball++;
            }
            else
            {
                out++;
            }

            nCount++;
            cout << "==========================" << endl;   // 스트라이크 볼 아웃 개수 알려주기
            cout << "스트라이크 : " << strike << endl;
            cout << "볼         : " << ball << endl;
            cout << "아웃       : " << out << endl;
            cout << "시도 횟수  : " << nCount << endl;
            cout << "==========================" << endl;

            if (strike == 3 || nCount == 10)
            {
                bGame = false;
                break;
            }
        }
        break;
    }
    
    system("pause");
    return 0;
}