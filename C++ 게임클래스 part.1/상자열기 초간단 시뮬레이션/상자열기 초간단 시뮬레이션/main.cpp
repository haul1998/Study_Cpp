#include "stdafx.h"

int main()
{
	srand(time(NULL));
	rand();

	int nRand[3];
	int nUser[3];
	int strike, ball, out;
	int nCount;
	bool bGame = true;
	bool bYN = true;



	while (bGame)
	{
		cout << "==========================================" << endl;
		cout << "       상자 열기 초간단 시뮬레이터" << endl;
		cout << "==========================================" << endl;
		cout << "   실제 게임과 최대한 비슷하게 구현하여 " <<
		endl << "  숫자 3개를 올바른 순서로 모두 맞추거나" <<
		endl << "  도전 횟수 10회를 넘기면 게임이 끝납니다." << endl;
		cout << "==========================================" << endl;

		nCount = 0;
		strike = ball = out = 0;

		nRand[0] = rand() % 9 + 1;
		while (true)
		{
			nRand[1] = rand() % 9 + 1;
			if (nRand[1] != nRand[0])
				break;
		}
		while (true)
		{
			nRand[2] = rand() % 9 + 1;
			if (nRand[2] != nRand[0] && nRand[2] != nRand[1])
				break;
		}

		strike = 0;

		while (strike < 3 || nCount < 11)
		{
			//cout << nRand[0] << nRand[1] << nRand[2] << endl;
			cout << "첫번 째 숫자를 고르세요. (1 ~ 9) : ";
			cin >> nUser[0];
			cout << "두번 째 숫자를 고르세요. (1 ~ 9) : ";
			cin >> nUser[1];
			cout << "세번 째 숫자를 고르세요. (1 ~ 9) : ";
			cin >> nUser[2];

			strike = ball = out = 0;

			for (int i = 0; i < 3; i++)
			{
				if (nUser[i] == nRand[i])
				{
					strike++;
				}
				else if (nUser[i] == nRand[(i + 1) % 3] || nUser[i] == nRand[(i + 2) % 3])
				{
					ball++;
				}
				else
				{
					out++;
				}
			}
			nCount++;

			cout << "스트라이크   : " << strike << endl
				<< "볼           : " << ball << endl
				<< "아웃         : " << out << endl;
			cout << "총 도전 횟수 : " << nCount << endl;
			cout << "==========================================" << endl;

			if (strike == 3)
			{
				system("cls");
				cout << "==========================================" << endl;
				cout << "       상자 열기 초간단 시뮬레이터" << endl;
				cout << "==========================================" << endl;
				cout << "   실제 게임과 최대한 비슷하게 구현하여 " <<
				endl << "  숫자 3개를 올바른 순서로 모두 맞추거나" <<
				endl << "  도전 횟수 10회를 넘기면 게임이 끝납니다." << endl;
				cout << "==========================================" << endl;
				cout << "		  CLEAR" << endl;
				break;
			}
			else if (nCount == 10)
			{
				system("cls");
				cout << "==========================================" << endl;
				cout << "       상자 열기 초간단 시뮬레이터" << endl;
				cout << "==========================================" << endl;
				cout << "   실제 게임과 최대한 비슷하게 구현하여 " <<
				endl << "  숫자 3개를 올바른 순서로 모두 맞추거나" <<
				endl << "  도전 횟수 10회를 넘기면 게임이 끝납니다." << endl;
				cout << "==========================================" << endl;
				cout << "                  FAIL" << endl;
				break;
			}
		}

		cout << "==========================================" << endl;
		cout << "정답 : " << nRand[0] << nRand[1] << nRand[2] << endl;
		cout << "총 도전 횟수 : " << nCount << endl;

		unsigned char chYN;
		cout << "새 게임(y, n) : ";
		cin >> chYN;
		system("cls");

		if (chYN == 'n' || chYN == 'N')
		{
			bGame = false;
		}
		else if (chYN == 'y' || chYN == 'Y')
		{
			cout << "==========================================" << endl;
			cout << "      상자 열기 초간단 시뮬레이터" << endl;
			cout << "==========================================" << endl;
			cout << "   실제 게임과 최대한 비슷하게 구현하여 " <<
			endl << "  숫자 3개를 올바른 순서로 모두 맞추거나" <<
			endl << "  도전 횟수 10회를 넘기면 게임이 끝납니다." << endl;
			cout << "==========================================" << endl;
			cout << "          게임을 재시작 합니다." << endl;
			cout << "==========================================" << endl;
			system("pause");
			system("cls");
			bGame = true;
		}
		else
		{
			cout << "잘못입력하셨습니다." << endl;
			bGame = false;
		}
	}
	cout << "==========================================" << endl;
	cout << "       상자 열기 초간단 시뮬레이터" << endl;
	cout << "==========================================" << endl;
	cout << "   실제 게임과 최대한 비슷하게 구현하여 " <<
	endl << "  숫자 3개를 올바른 순서로 모두 맞추거나" <<
	endl << "  도전 횟수 10회를 넘기면 게임이 끝납니다." << endl;
	cout << "==========================================" << endl;
	cout << "           게임을 종료합니다." << endl;
	cout << "==========================================" << endl;


	system("pause");
	return 0;
}