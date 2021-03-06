// ConsoleApplication11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

// 열거문 enum
// enum 은 여러가지 상태 값을 문자로 표현 할 수 있다. (가독성이 증가)
// 값을 순차적으로 증가시키며 관리 한다. (값을 임의로 넣는 경우 임의로 정해준 값부터 뒤쪽으로 1씩 증가한다.)
// 이넘문으로 선언 된 변수에 설정 된 값에 대한 제한을 걸 수 있다.
enum E_NUMBERS { EN_ZERO, EN_ONE, EN_TWO, EN_TRHEE, EN_TEN = 10, EN_ELEVEN };

// 캐릭터의 상태값
enum E_STATE { E_IDLE = 0, E_MOVE_LEFT, E_MOVE_RIGHT, E_MOVE_UP, E_MOVE_DOWN, E_FIGHT };
// 전투 중 캐릭터의 상태값
enum E_FIGHTING { E_RUNAWAY, E_ATTACK, E_MAGIC, E_DEFENCE };
// 몬스터 종류
enum E_MONTYPE { E_ORC, E_DARKELF, E_TROLL, E_HUMAN, E_MON_MAX };

int main()
{
	srand(time(NULL));
	rand();

	E_STATE eState = E_IDLE;		// 캐릭터의 현제 상태
	int nHp = 100;					// 캐릭터의 체력
	int nCoordX = 0, nCoordY = 0;	// 캐릭터의 위치
	int nSelect;					// 행동을 입력 받기 위한 변수

	// 몬스터의 수 만큼 배열 할당
	int nMonHp[E_MON_MAX];
	int nMonX[E_MON_MAX];
	int nMonY[E_MON_MAX];

	for (int i = 0; i < E_MON_MAX; i++)
	{
		nMonHp[i] = 100;
		nMonX[i] = 5 + i * 5;
		nMonY[i] = 0;
	}

	while (true)
	{
		system("cls");

		cout << "현재 위치 : X(" << nCoordX << ") Y(" << nCoordY << ")" << endl;
		
		if (eState == E_IDLE)
			cout << "입력하시오. (0.대기 1.왼쪽 2.오른쪽 3.위쪽 4.아래쪽) : ";
		else if (eState == E_FIGHT)
			cout << "입력하시오. (0.도망 1.공격 2.마법공격 3.방어) : ";

		cin >> nSelect;

		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);

		if (eState == E_IDLE)
		{
			switch (nSelect)
			{
				case E_IDLE:
				{
					cout << "한턴 휴식" << endl;
				}
				break;
				case E_MOVE_LEFT:
				{
					cout << "왼쪽으로 한칸 이동" << endl;
					nCoordX--;
				}
				break;
				case E_MOVE_RIGHT:
				{
					cout << "오른쪽으로 한칸 이동" << endl;
					nCoordX++;
				}
				break;
				case E_MOVE_UP:
				{
					cout << "위쪽으로 한칸 이동" << endl;
					nCoordY++;
				}
				break;
				case E_MOVE_DOWN:
				{
					cout << "아래쪽으로 한칸 이동" << endl;
					nCoordY--;
				}
				break;
				default:
				{
					cout << "잘 못 된 입력! 강제로 한턴 휴식!" << endl;
				}
				break;
			}

			for (int i = 0; i < E_MON_MAX; i++)
			{
				if (nCoordX == nMonX[i] && nCoordY == nMonY[i])
				{
					switch (i)
					{
					case E_ORC:
						cout << "오크를 만났다!!" << endl;
						break;
					case E_DARKELF:
						cout << "다크엘프를 만났다!!" << endl;
						break;
					case E_TROLL:
						cout << "트롤 만났다!!" << endl;
						break;
					case E_HUMAN:
						cout << "도적을 만났다!!" << endl;
						break;
					}

					eState = E_FIGHT;
				}
			}
		}
		else if (eState == E_FIGHT)
		{
			switch (nSelect)
			{
				case E_RUNAWAY:
				{
					int nRand = rand() % 2;
					if (nRand == 0)
					{
						cout << "도주 성공!!!" << endl;
						nCoordX += 1;
						eState = E_IDLE;	// 전투 해제
					}
					else
					{
						cout << "도주 실패!!!" << endl;
					}
				}
				break;
				case E_ATTACK:
				{

				}
				break;
				case E_MAGIC:
				{

				}
				break;
				case E_DEFENCE:
				{

				}
				break;
				default:
				{
					cout << "잘 못 된 입력! 강제로 한턴 휴식!" << endl;
				}
				break;
			}
		}

		Sleep(2000);
	}

	system("pause");

    return 0;
}

