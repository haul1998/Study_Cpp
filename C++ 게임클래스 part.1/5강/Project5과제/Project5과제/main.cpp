// 이번 구문 또한 무한 무승부로 인한 루프를 만들 수 없기 때문에 무승부일 경우 재경기로 재시작으로 설정
// 이하 다른 조건은 이전 과제랑 조건을 독같이 설정

#include "stdafx.h"

int main()
{
    srand(time(NULL));
    rand();

    int nCom;
    int nPlayer;
    int nCW = 0;
    int nPW = 0;
    bool isContinue = true;

    while (true)
    {
        nCom = rand() % 3;

        cout << "=====================================" << endl;
        cout << "1.가위, 2.바위, 3.보 : ";
        cin >> nPlayer;
        cout << "=====================================" << endl;
        cout << "컴퓨터 : " << nCom << endl << "플레이어 : " << nPlayer << endl;


        if (nCom == nPlayer)
            cout << "결과 : 무승부!!" << endl;

        else if (nCom + 1 % 3 < nPlayer)
        {
            cout << "=====================================" << endl;
            cout << "플레이어 선공!!" << endl;
            cout << "1.묵, 2.찌, 3.빠 : ";
            cin >> nPlayer;
            nCom = rand() % 3;
            cout << "=====================================" << endl;

            if (nCom == nPlayer)
                cout << "결과 : 무승부!!" << endl;

            else if (nCom + 1 % 3 < nPlayer)
            {
                cout << "플레이어 승!!" << endl;
                nPW++;
            }

            else
            {
                cout << "컴퓨터 승!!" << endl;
                nCW++;
            }
        }

        else
        {
            cout << "=====================================" << endl;
            cout << "" << endl;
            cout << "컴퓨터 선공!!" << endl;
            nCom = rand() % 3;
            cout << "컴퓨터 : " << nCom << endl;
            cout << "1.묵, 2.찌, 3.빠 : ";
            cin >> nPlayer;
            cout << "=====================================" << endl;

            if (nCom == nPlayer)
                cout << "결과 : 무승부!!" << endl;

            else if ((nCom + 1) % 3 < nPlayer)
            {
                cout << "플레이어 승!!" << endl;
                nPW++;
            }

            else
            {
                cout << "컴퓨터 승!!" << endl;
                nCW++;
            }
        }

        cout << "승리 횟수 - 플레이어 : " << nPW << " : " << nCW << " : 컴퓨터" << endl;

        if (nPW == 2)
        {
            cout << "최종 승리 : 플레이어" << endl;
            break;
        }

        else if (nCW == 2)
        {
            cout << "최종 승리 : 컴퓨터" << endl;
            break;
        }
    }

    system("pause");

    return 0;
}