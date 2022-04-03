#include "stdafx.h"

// switch : 조건문과 비슷하지만 선택지를 만들 때 조금 더 간단하고 편리하게 사용이 가능하다.

// 열거문  enum
// enum 은 여러가지 상태의 값을 문자로 표현할 수 있다. (가독성이 증가)
// 값을 순차적으로 증가시키며 관리한다.
// enum문으로 선언 된 변수에 설정된 값에 대한 제한을 걸 수 있다.

// 전투 중 캐릭터의 상태값
enum E_FIGHTING
{
    E_RUN = 0, E_nAttack, E_MAGIC, E_DEFFENCE
};

// 몬스터 종류
enum E_MONTYPE
{
    E_ORC, E_DARKELF, E_TROL, E_MON_MAX
};

// 캐릭터의 상태값
enum E_STATE
{
    E_IDLE = 0, E_MOVE_LEFT, E_MOVE_RIGHT, E_MOVE_UP, E_MOVE_DOWN, E_FIGHT, E_STATE_NMAX
};

enum E_MON_MOVE
{
    E_MON_IDLE = 0, E_MON_LEFT, E_MON_RIGHT, E_MON_UP, E_MON_DOWN
};

enum E_NUMBERS
{
    EN_ZERO, EN_ONE, EN_TWO, EN_THREE, EN_TEN = 10, EN_ELEVEN, EN_MAX   //0, 1, 2, 3, 4 가 입력되어있다 / 값을 입력할 경우 임의로 조정이 가능하며 지정한 값부터 1씩 증가한다
};

int main()
{
    srand(time(NULL));
    rand();



    /*
     int nCondition = rand() % 5;

     switch (nCondition)
     {
     case 0: // if 와 else if와 같은 개념
         cout << "0번 선택" << endl;
         cout << "출력0" << endl;
         cout << endl;
         break;

     case 1:
         cout << "1번 선택" << endl;
         cout << "출력1" << endl;
         cout << endl;
         break;

     case 2:
         cout << "2번 선택" << endl;
         cout << "출력2" << endl;
         cout << endl;
         break;

     default: //else 와 같은 개념
         cout << "이외의 것이 나왔다." << endl;
         break;
     }
     */ 

     /*
     E_STATE eState = E_IDLE;
     switch (eState)
     {
     case E_IDLE:
         break;
     case E_MOVE_LEFT:
         break;
     case E_MOVE_RIGHT:
         break;
     case E_MOVE_UP:
         break;
     case E_MOVE_DOWN:
         break;
     case E_FIGHT:
         break;
     case E_STATE_NMAX:
         break;
     default:
         break;
     }
     */

    E_STATE eState = E_IDLE;
    int nHP = 100;                  // 플레이어의 체력
    int nCoordX = 10, nCoordY = 0;   // 플레이어 캐릭터의 시작점 위치, 좌표를 숫자로 표시할 에정
    int nSelect;                    // 행동을 입력받기 위한 변수

    int nMonHP[E_MON_MAX];          // MAX 값으로 몬스터의 수만큼 배열을 만들어줌, 나중에 종류를 늘려도 같이 값이 늘어나기에 추가하기 유용함
    int nMonX[E_MON_MAX];
    int nMonY[E_MON_MAX];
    int nMonMove;

    for (int i = 0; i < E_MON_MAX; i++)
    {
        nMonHP[i] = 100;
        nMonX[i] = 5 + i * 5 + 1;
        nMonY[i] = 0;               // 몬스터 만나기 쉽게 임시로 y좌표 값을 임시로 0으록 고정
        //nMonX[1] = 5;
    }

    while (true)
    {
        system("cls");
        if (eState == E_IDLE)
        {

            cout << "==================================================" << endl;
            cout << "캐릭터 위치 (x , y) : (" << nCoordX << " , " << nCoordY << ")" << endl;
            for (int i = 0; i < E_MON_MAX; i++)
            {
                cout << "몬스터 위치 (x , y) : (" << nMonX[i] << " , " << nMonY[i] << ")" << endl;
            }
            cout << "입력 (0.대기 1.왼쪽 2.오른쪽 3.위쪽 4.아래쪽) : ";
            cin >> nSelect;

            switch (nSelect)
            {
                cout << "==================================================" << endl;
            case E_IDLE:
            {
                cout << "이번 턴은 휴식을 취합니다." << endl;
            }
            break;
            case E_MOVE_LEFT:
            {
                cout << "왼쪽으로 한 칸 이동합니다." << endl;
                nCoordX -= 1;
            }
            break;
            case E_MOVE_RIGHT:
            {
                cout << "오른쪽으로 한 칸 이동합니다." << endl;
                nCoordX += 1;
            }
            break;
            case E_MOVE_UP:
            {    cout << "위쪽으로 한 칸 이동합니다." << endl;
            nCoordY += 1;
            }
            break;
            case E_MOVE_DOWN:
            {
                cout << "아래쪽으로 한 칸 이동합니다." << endl;
                nCoordY -= 1;
            }
            break;

            default:
            {
                cout << "잘못된 입력입니다. 강제로 한턴 휴식!!" << endl;
            }
            break;
            }
            cout << "==================================================" << endl;
            Sleep(250);
            cout << "로";
            Sleep(250);
            cout << "딩";
            Sleep(250);
            cout << "중";
            Sleep(250);
            cout << ".";
            Sleep(250);
            cout << ".";
            Sleep(250);
            cout << "." << endl;
            Sleep(150);
            cout << "==================================================" << endl;

            for (int i = 0; i < E_MON_MAX; i++)
            {
                if (nCoordX == nMonX[i] && nCoordY == nMonY[i])
                {

                    switch (i)
                    {
                    case E_ORC:
                    {
                        cout << "오크";
                    }
                    break;

                    case E_DARKELF:
                    {
                        cout << "다크엘프";
                    }
                    break;

                    case E_TROL:
                    {
                        cout << "오크";
                    }
                    break;
                    }
                    cout << "와 조우했다!!" << endl;
                    eState = E_FIGHT;
                }
            }
            system("pause");
        }
        


        else if (eState == E_FIGHT)  // 전투 진입
        {

            for (int i = 0; i < E_MON_MAX; i++)
            {
                if (nCoordX == nMonX[i] && nCoordY == nMonY[i])
                {
                    system("cls");
                    cout << "==================================================" << endl;
                    cout << "캐릭터 남은 체력 : " << nHP << endl;
                    cout << "몬스터 남은 체력 : " << nMonHP[i] << endl;
                    cout << "입력(0.도망 1.공격 2.마법공격 3.방어) : ";
                    cin >> nSelect;
                    cout << "==================================================" << endl;
                    int nMonAttack = rand() % 30;
                    switch (nSelect)
                    {
                    case E_RUN:
                    {
                        int nRand = rand() % 2;
                        if (nRand == 0)
                        {
                            cout << "도주 성공!!" << endl;
                            nCoordX += rand() % 3 + 1;
                            eState = E_IDLE;
                        }
                        else
                        {
                            cout << "도주 실패..." << endl;
                        }
                        system("pause");

                        break;
                    }
                    case E_nAttack:
                    {
                        int nAttack = rand() % 100;
                        nMonHP[i] = nMonHP[i] - nAttack;
                        cout << nAttack << "만큼의 데미지를 입혔습니다." << endl;

                    }
                    break;
                    case E_MAGIC:
                    {
                        int nMagicAttack = rand() % 150;
                        nMonHP[i] = nMonHP[i] - nMagicAttack;
                        cout << nMagicAttack << "만큼의 데미지를 입혔습니다." << endl;
                    }
                    break;
                    case E_DEFFENCE:
                    {
                        cout << "방어를 했다." << endl;
                        nMonAttack = 0;
                    }
                    break;
                    }

                    if (nMonHP[i] <= 0)
                    {
                        cout << "전투에 승리했다!!" << endl;
                        eState = E_IDLE;
                        nMonHP[i] = 100;
                    }
                    else if (nMonHP[i] > 0)
                    {
                        nHP = nHP - nMonAttack;
                        cout << nMonAttack << "만큼의 피해를 입었습니다." << endl;
                    }
                    if (nHP <= 0)
                    {
                        cout << "사망하였습니다." << endl;
                    }
                    cout << "==================================================" << endl;
                    system("pause");
                }
            }
        }
        if (eState == E_IDLE) // 미 전투 시 몬스터 이동
        {
            for (int i = 0; i < E_MON_MAX; i++)
            {
                nMonMove = rand() % 4;
                if (nMonMove == 0)
                {
                    nMonX[i] -= 1;
                }
                else if (nMonMove == 1)
                {
                    nMonX[i] += 1;
                }
                else if (nMonMove == 2)
                {
                    nMonY[i] -= 1;
                }
                else
                {
                    nMonY[i] += 1;
                }
            }
        }
    }
    system("pause");
    return 0;
}