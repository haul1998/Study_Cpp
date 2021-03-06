// ConsoleApplication13.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void InitTable(int* table);
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
	int nUserBingo = 0;
	int nComTable[25];
	int nComBingo = 0;

	// 게임 진행 변수 선언
	bool isPlaying = true;
	bool isMyTurn = true;

	// 게임 진행
	while (isPlaying)
	{
		// 게임 초기화
		InitTable(nUserTable);
		InitTable(nComTable);

		while (true)
		{
			system("cls");

			// 빙고 확인
			nUserBingo = CheckBingo(nUserTable);
			nComBingo = CheckBingo(nComTable);

			// 테이블 확인
			HideTable(nComTable);
			cout << "컴퓨터 빙고 : " << nComBingo << endl << endl;
			ShowTable(nUserTable);
			cout << "유저 빙고 : " << nUserBingo << endl << endl;

			if (nUserBingo >= 3 && nComBingo >= 3)
			{
				cout << "빙고 동시 달성~!!! 비겼다." << endl;
				break;
			}
			else if (nUserBingo >= 3)
			{
				cout << "유저 빙고 달성~!!! 이겼다." << endl;
				break;
			}
			else if (nComBingo >= 3)
			{
				cout << "컴퓨터 빙고 달성~!!! 졌다." << endl;
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
		}

		// 게임 종료 선택
		cout << "0.게임 종료, 1.새 게임 : ";
		cin >> isPlaying;
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
	int nTemp;

	for (int i = 0; i < 250; i++)
	{
		nSrc = rand() % 25;
		nDest = rand() % 25;

		nTemp = table[nSrc];
		table[nSrc] = table[nDest];
		table[nDest] = nTemp;
	}
}

void ShowTable(int* table)
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

void HideTable(int* table)
{
	cout << "=========================================" << endl;
	for (int i = 0; i < 25; i++)
	{
		if (table[i] == 0)
			cout << "|  0\t|";
		else
			cout << "|  ?\t|";

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
			// 0 => 테이블에서 이미 선택 된 숫자를 의미
			userTable[i] = 0;

			// 컴퓨터 테이블도 똑같은 숫자를 처리
			for (int j = 0; j < 25; j++)
			{
				if (nSelect == comTable[j])
				{
					comTable[j] = 0;
					break;
				}
			}
			break;
		}

		// 선택 한 숫자를 찾지 못 한 경우
		if (i == 24)
		{
			cout << "제대로 선택해라!!" << endl;
			Sleep(1000);
		}
	}
}

/*
[5] [1] [2] [1] [X]
[0] [4] [1] [5] [2]
[2] [2] [X] [2] [X]
[0] [5] [1] [4] [2]
[5] [0] [1] [0] [6]
*/
void ComSelect(int* userTable, int* comTable)
{
	int nIndex = 0;
	int nSelect;

	cout << "컴퓨터 선택 중";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << "." << endl;

	while (true) // 이전에 선택 된 적이 없는 칸(배열의 Index)을 선택 한다.
	{
		nIndex = rand() % 25;
		nSelect = comTable[nIndex];

		if (nSelect != 0) // 숫자가 남은 칸을 찾았으면
		{
			for (int i = 0; i < 25; i++) // 유저 테이블에서 선택 된 숫자를 처리 하고
			{
				if (nSelect == userTable[i])
				{
					userTable[i] = 0;
					break;
				}
			}

			comTable[nIndex] = 0;	// 컴퓨터 테이블에서도 선택 된 숫자를 처리 한다.
			break;
		}
	}

	cout << "컴퓨터 선택 : " << nSelect << endl;
	Sleep(2000);
}

int CheckBingo(int* table)
{
	int nBingo = 0;

	// 가로 검사 5
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (table[i * 5 + j] == 0) // 한칸씩 선택 유무 확인
			{
				if (j == 4) // 제일 마지막칸까지 선택이 되어 있는 경우라면
					nBingo++;
			}
			else
				break;
		}
	}

	/*
	0	1	2	3	4
	5	6	7	8	9
	10	11	12	13	14
	15	16	17	18	19
	20	21	22	23	24
	*/

	// 세로 검사 5
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (table[i + j * 5] == 0) // 한칸씩 선택 유무 확인
			{
				if (j == 4) // 제일 마지막칸까지 선택이 되어 있는 경우라면
					nBingo++;
			}
			else
				break;
		}
	}

	// 왼쪽 사선
	for (int i = 0; i < 5; i++)
	{
		if (table[i * 5 + i] == 0)
		{
			if (i == 4) // 제일 마지막칸까지 선택이 되어 있는 경우라면
				nBingo++;
		}
		else
			break;
	}

	// 오른쪽 사선
	for (int i = 0; i < 5; i++)
	{
		if (table[(i + 1) * 4] == 0)
		{
			if (i == 4) // 제일 마지막칸까지 선택이 되어 있는 경우라면
				nBingo++;
		}
		else
			break;
	}

	return nBingo;
}