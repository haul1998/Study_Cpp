#include <iostream>
#include "stdafx.h"

using namespace std;

void main()
{
	srand(time(NULL)); //난수 생성기 초기화, 메모리에 가끔 불필요한 값이 들어있을 수도 있기 때문에 초기화 해줘야한다.
	rand(); // 버그 방지를 위해 난수 생성함수를 호출 사용!!

	// Mod 연산자(%) : 연산자가 나누고 남은 나머지 값
	// 예) 20 / 2 = 10, 20 / 3 = 6 (정수아닌 소수점은 버린다.
	// 예) 20 % 2 = 0, 20 / 3 = 2

	int nA = rand() % 10; // rand를 10으로 나누면 0 ~ 9 까지 나오기 떄문에 10보다 작은 0 ~ 9 사이의 난수가 생성된다.

	int nCom = rand() % 3; // 0 ~ 2 까지의 난수 생성
	int nPlayer;
	//cout << "1.가위, 2. 바위, 3. 보 : "; // 밑에 주석처리 한 것과 세트
	cout << "0.가위, 1. 바위, 2. 보 : ";
	cin >> nPlayer;
	//nPlayer -= 1;  // A = A + 1 은 A += 1 과 같다. +-*/ 모두 가능하다.  즉 nPlayer = nPlayer + 1 과 같다는 뜻

	cout << "컴퓨터 : " << nCom << " vs " << "플레이어 : " << nPlayer << endl;
	/*
	if (nCom == 0) // 컴퓨터 가위
	{
		cout << "컴 : 가위 VS";
		if (nPlayer == 0)
			cout << "플레이어 : 가위" << endl << "무승부" << endl;
		else if (nPlayer == 1)
			cout << "플레이어 : 바위" << endl << "플레이어 승" << endl;
		else
			cout << "플레이어 : 보" << endl << "컴퓨터 승" << endl;
	}

	else if (nCom == 1) // 컴퓨터 바위
	{
		if (nPlayer == 0)
			cout << "플레이어 : 가위" << endl << "컴퓨터 승" << endl;
		else if (nPlayer == 1)
			cout << "플레이어 : 바위" << endl << "무승부" << endl;
		else
			cout << "플레이어 : 보" << endl << "플레이어 승" << endl;
	}

	else  // 컴퓨터 보
	{
		if (nPlayer == 0)
			cout << "플레이어 : 가위" << endl << "플레이어 승" << endl;
		else if (nPlayer == 1)
			cout << "플레이어 : 바위" << endl << "컴퓨터 승" << endl;
		else
			cout << "플레이어 : 보" << endl << "무승부" << endl;
	}
	*/
	//간단하게 짜는 법
	// 0 < 1, 1 < 2, 2 < 0
	if (nCom == nPlayer)
		cout << "무승부" << endl;

	else if ((nCom + 1) % 3 == nPlayer)		  // 0 -> 1 / 1 -> 2  / 2 -> 3 으로 변해서 3이 된 보는 0이 된다.
		cout << "플레이어 승" << endl;	 	 // 컴 : 가위(1) - 플레이어 : 가위(0) / "바위 : (1)" < 보 : (2)
											// 컴 : 바위(2) - 플레이어 : 가위(0) / 바위 : (1) < "보 : (2)"
										   // 컴 : 보(0)  - 플레이어 : "가위(0)" / 바위 : (1) < 보 : (2)
	else
		cout << "컴퓨터 승" << endl;

	system("pause");
}