#include "stdafx.h"

// 테이블 값 만들어 넣기
void InitTable(int* table);
// 유저 테이블
void UserTable(int* table);
// 가려진 컴퓨터 테이블
void ComTable(int* table);
// 유저 선택
void UserSelect(int* userTable, int* comTable);
// 컴퓨터 선택
void ComSelect(int* userTable, int* comTable);
// 빙고 체크
int CheckBingo(int* table);

int main()
{
    srand(time(NULL));
    rand();

    int userTable[25];
    int comTable[25];

    int nSelect;
    int userBigno = 0;
    int comBingo = 0;

    bool bGame = true;
    bool bRun = true;
    bool bMyTurn = true;

    while (bGame)
    {
        InitTable(userTable);
        InitTable(comTable);

        while (bRun)
        {
            system("cls");

            userBigno = CheckBingo(userTable);
            comBingo = CheckBingo(comTable);

            UserTable(userTable);
            cout << "유저 빙고 : " << userBigno << endl;
            ComTable(comTable);
            cout << "컴퓨터 빙고 : " << comBingo << endl;


            if (userBigno >= 3 && comBingo >= 3)
            {
                cout << "비겼습니다." << endl;
                bRun = false;
            }
            else if (userBigno >= 3)
            {
                cout << "승리" << endl;
                bRun = false;
            }
            else if (comBingo >= 3)
            {
                cout << "패배" << endl;
                bRun = false;
            }

            if (bMyTurn)
            {
                UserSelect(userTable, comTable);
                bMyTurn = false;
            }
            else
            {
                ComSelect(userTable, comTable);
                bMyTurn = true;
            }
        }
        cout << "0. 게임 종료 1. 새 게임 : ";
        cin >> nSelect;
        if (nSelect == 0)
        {
            bGame = false;
        }
        else if (nSelect == 1)
        {
            bRun = true;
        }
        else
        {
            cout << "잘못 입력하였습니다." << endl;
        }
    }
    return 0;
}

void InitTable(int* table)
{
    for (int i = 0; i < 25; i++)
    {
        table[i] = i + 1;
    }

    int nSrc;
    int nDest;

    for (int i = 0; i < 250; i++)
    {
        nSrc = rand() % 25;
        nDest = rand() % 25;

        int Temp = table[nSrc];
        table[nSrc] = table[nDest];
        table[nDest] = Temp;
    }
}

void UserTable(int* table)
{
    cout << "=========================================" << endl;
    for (int i = 0; i < 25; i++)
    {
        cout << "|  " << table[i] << "\t|";
        if (i % 5 == 4)
        {
            cout << endl;
            cout << "=========================================" << endl;
        }

    }
}
void ComTable(int* table)
{
    cout << "=========================================" << endl;
    for (int i = 0; i < 25; i++)
    {
        if (table[i] == 0)
        {
            cout << "|  " << "0" << "\t|";
        }
        else
        {
            cout << "|  " << "?" << "\t|";
        }
        if (i % 5 == 4)
        {
            cout << endl;
            cout << "=========================================" << endl;
        }
    }
}
void UserSelect(int* userTable, int* comTable)
{
    int nUserSelect;
    cout << "선택 (1 ~ 25) : ";
    cin >> nUserSelect;

    for (int i = 0; i < 25; i++)
    {
        if (nUserSelect == userTable[i])
        {
            userTable[i] = 0;

            for (int j = 0; j < 25; j++)
            {
                if (nUserSelect == comTable[j])
                {
                    comTable[j] = 0;
                    break;
                }
            }
        }
        if (i == 24)
        {
            cout << "3초 후 턴이 넘어갑니다." << endl;
            Sleep(3000);
        }
    }
}
void ComSelect(int* userTable, int* comTable)
{
    int nComSelect;
    /*
    cout << "컴퓨터 선택중";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << endl;
    */
    while (true)
    {
        nComSelect = rand() % 25 + 1;

        for (int i = 0; i < 25; i++)
        {
            if (nComSelect == userTable[i])
            {
                userTable[i] = 0;
            }
        }
        for (int i = 0; i < 25; i++)
        {
            if (nComSelect == comTable[i])
            {
                comTable[i] = 0;
            }
        }
        cout << "컴퓨터 선택 : " << nComSelect << endl;
        break;
    }
    cout << "3초 후 턴이 넘어갑니다." << endl;
    Sleep(3000);
}
/*
0  1  2  3  4
5  6  7  8  9
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24
*/
int CheckBingo(int* table)
{
    int nBingo = 0;
    // 가로
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (table[(i * 5) + j] == 0)
            {
                if (j == 4)
                {
                    nBingo++;
                }
            }
            else
            {
                break;
            }
        }
    }
    // 세로
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (table[(i + 5) * j] == 0)
            {
                if (j == 4)
                {
                    nBingo++;
                }
            }
            else
            {
                break;
            }
        }
    }
    // 좌대각
    for (int i = 0; i < 5; i++)
    {
        if (table[(i * 5) + i] == 0)
        {
            if (i == 4)
            {
                nBingo++;
            }
        }
        else
        {
            break;
        }
    }
    // 우대각
    for (int i = 0; i < 5; i++)
    {
        if (table[(i + 1) * 4] == 0)
        {
            if (i == 4)
            {
                nBingo++;
            }
        }
        else
        {
            break;
        }
    }
    return nBingo;
}