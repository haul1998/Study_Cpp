#include "stdafx.h"

void InitTable(int* table);        // 메인 함수가 찾을 수 있도록 전방선언 해야한다.
void ShowTable(int* table);
void HideTable(int* table);
void UserSelect(int* userTable, int* comTable);
void ComSelect(int* userTable, int* comTable);
int CheckBingo(int* table);


int main()
{
    // 랜덤 초기화
    srand(time(NULL));
    rand();

    // 테이블 배열과 빙고 변수 선언
    int nUserTable[25];
    int nComTable[25];
    
    int nUserBingo = 0;
    int nComBingo = 0;

    // 게임 진행 변수 선언
    bool isPlaying = true;
    bool isMyTurn = true;

    // 게임 진행
    while (isPlaying)
    {
        // 플레이
        InitTable(nUserTable);      // InitTable을 메인 함수 밑에 내려두면 오류 줄은 발생하지 않지만 main함수가 돌아가면서 해당 함수를 찾을 수 없어서 실행이 되지 않는다. .
        InitTable(nComTable);

        while (true)
        {
            system("cls");

            // 테이블 확인
            ShowTable(nUserTable);
            cout << "유저 빙고   : " << nUserBingo << endl;
            HideTable(nComTable);
            cout << "컴퓨터 빙고 : " << nComBingo << endl;

            // 빙고 확인
            nUserBingo = CheckBingo(nUserTable);
            nComBingo = CheckBingo(nComTable);

            if (nUserBingo >= 3 && nComBingo >= 3)
            {
                cout << "동점" << endl;
                break;
            }
            else if (nUserBingo >= 3)
            {
                cout << "승리" << endl;
                break;
            }
            else if (nComBingo >= 3)
            {
                cout << "패배" << endl;
                break;
            }
            

            // 번호 선택
            if (isMyTurn)
            {
                UserSelect(nUserTable, nComTable);
                isMyTurn = false;
            }
            else
            {
                ComSelect(nUserTable, nComTable);
                isMyTurn = true;
            }
            system("pause");
        }
        // 게임 종료 선택
        cout << "0.게임 종료, 1. 새 게임 : ";
        cin >> isPlaying;
    }

    return 0;
}

void InitTable(int* table)          // 위쪽에 전방 선언을 해두고 아래에 작성해도 사용이 가능하다.
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

void ShowTable(int* table)
{
    cout << "=========================================" << endl;
    for (int i = 0; i < 25; i++)
    {
        cout << "|  " << table[i] << " \t|";

        if (i % 5 == 4)
        {
            cout << endl;
            cout << "=========================================" << endl;
        }
    }
}

void HideTable(int* table)
{
    cout << "=========================================" << endl;
    for (int i = 0; i < 25; i++)
    {
        if (table[i] == 0)
        {
            cout << "|  0" << " \t|";
        }
        else
        {
            cout << "|  ?" << " \t|";
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
    int nSelect;
    
    cout << "선택 (1 ~ 25) : ";
    cin >> nSelect;

    // 테이블 전체를 검사
    for (int i = 0; i < 25; i++)
    {
        if (nSelect == userTable[i])
        {
            // 0 -> 테이블에서 이미 선택된 숫자를 의미
            userTable[i] = 0;

            for (int j = 0; j < 25; j++)
            {
                if (nSelect == comTable[j])
                {
                    comTable[j] = 0;
                }
            }
            break;
        }
        // 선택 한 숫자를 찾지 못한 경우
        if (i == 24)
        {
            cout << "선택한 숫자를 찾지 못했습니다." << endl;
            Sleep(1000);
        }
    }
}

void ComSelect(int* userTable, int* comTable)
{
    cout << "컴퓨터 선택중";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << endl;

    int nComSelect = 0;
    while (true)    // 이전에 선택된 적이 없는 칸(배열의 Index)을 선택한다.
    {
        nComSelect = rand() % 25 + 1;
            
        if (comTable[nComSelect] != 0)  // 숫자가 남는 칸을 찾았으면
        {
            for (int i = 0; i < 25; i++)    // 유저 테이블에서 선택된 숫자를 처리하고
            {
                if (nComSelect == userTable[i])
                {
                    userTable[i] = 0;
                    
                    break;
                }
            }
            for (int i = 0; i < 25; i++)    // 유저 테이블에서 선택된 숫자를 처리하고
            {
                if (nComSelect == comTable[i])
                {
                    comTable[i] = 0;
                    break;
                }
            }
            //comTable[nComSelect] = 0;   // 컴퓨터 테이블에서도 똑같은 숫자를 처리한다.
            break;
        }
    }
    cout << "컴퓨터 선택 : " << nComSelect << endl;
}

int CheckBingo(int* table)
{
    int nBingo = 0;
    // 가로 검사 5
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (table[i * 5 + j] == 0)  // 한칸씩 체크
            {
                if (j == 4)             // 제일 마지막 칸까지 선택이 되어 있는 경우라면
                {
                    nBingo += 1;        // 빙고 + 1
                }
            }
            else
            {
                break;
            }
        }
    }
    // 세로 검사 5
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (table[i + 5 * j] == 0)  // 한칸씩 체크
            {
                if (j == 4)             // 제일 마지막 칸까지 선택이 되어 있는 경우라면
                {
                    nBingo += 1;        // 빙고 + 1
                }
            }
            else
            {
                break;
            }
        }
    }
    // 왼쪽 사선
    for (int i = 0; i < 5; i++)
    {
        if (table[(i * 5) + i] == 0)
        {
            if (i == 4)
            {
                nBingo++;
            }
            else
            {
                break;
            }
        }
    }
    // 오른쪽 사선
    for (int i = 0; i < 5; i++)
    {
        if (table[(i + 1) * 4] == 0)
        {
            if (i == 4)
            {
                nBingo++;
            }
            else
            {
                break;
            }
        }
    }
    return nBingo;
}