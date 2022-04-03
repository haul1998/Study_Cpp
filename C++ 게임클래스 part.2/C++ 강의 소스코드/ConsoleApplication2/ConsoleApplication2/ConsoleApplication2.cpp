// ConsoleApplication2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	srand(time(NULL));
	rand();

	// Mode 연산자 %
	// 20 / 2 = 10, 20 / 3 = 6
	// 20 % 2 = 0, 20 % 3 = 2

	int nA = rand() % 10; // 0 ~ 9

	int nCom = rand() % 3; // 0 ~ 2 : 0 가위 1 바위 2 보

	int nPlayer;
	cout << "0.가위 1.바위 2.보 : ";
	cin >> nPlayer;
	//nPlayer -= 1; // nPlayer = nPlayer - 1;

	cout << "컴퓨터: " << nCom << " vs " << nPlayer << " :플레이어" << endl;

	// 0 < 1, 1 < 2, 2 < 0
	if (nCom == nPlayer)
		cout << "무승부" << endl;
	else if ((nCom + 1) % 3 == nPlayer)
		cout << "플레이어 승" << endl;
	else
		cout << "컴퓨터 승" << endl;

	//if (nCom == 0)	// 컴퓨터 가위
	//{
	//	cout << "컴: 가위 vs ";

	//	if (nPlayer == 0)
	//		cout << "가위 :플레이어" << endl << "무승부" << endl;
	//	else if (nPlayer == 1)
	//		cout << "바위 :플레이어" << endl << "플레이어 승" << endl;
	//	else
	//		cout << "보 :플레이어" << endl << "컴퓨터 승" << endl;
	//}
	//else if (nCom == 1)	// 컴퓨터 바위
	//{
	//	cout << "컴: 바위 vs ";

	//	if (nPlayer == 0)
	//		cout << "가위 :플레이어" << endl << "컴퓨터 승" << endl;
	//	else if (nPlayer == 1)
	//		cout << "바위 :플레이어" << endl << "무승부" << endl;
	//	else
	//		cout << "보 :플레이어" << endl << "플레이어 승" << endl;
	//}
	//else // 컴퓨터 보
	//{
	//	cout << "컴: 보 vs ";

	//	if (nPlayer == 0)
	//		cout << "가위 :플레이어" << endl << "플레이어 승" << endl;
	//	else if (nPlayer == 1)
	//		cout << "바위 :플레이어" << endl << "컴퓨터 승" << endl;
	//	else
	//		cout << "보 :플레이어" << endl << "무승부" << endl;
	//}

	system("pause");

    return 0;
}

