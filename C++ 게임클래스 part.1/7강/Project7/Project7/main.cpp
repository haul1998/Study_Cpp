#include "stdafx.h"

/*
숫자야구게임
1 ~ 9까지의 숫자 중에 컴퓨터가 랜덤하게 중복되지 않는 3개의 숫자를 선택하고 플레이어가 3개의 숫자를 맞추는 게임
예) 6 2 3

- 반복 -
숫자 3개를 순차적으로 고른다. 예) 2 0 3 볼 아웃 스트라이크
스트라이크 : 1
볼 : 1
아웃 : 1
- 반복 -
*/

int main()
{
	srand(time(NULL));
	rand();

	int nRand1, nRand2, nRand3;
	int nUser1, nUser2, nUser3;
	int strike, ball, out;
	
	int nCount = 0;
	bool bGame = true;

	while (bGame) // 유저의 선택에 의해 게임이 반복됨
	{
		//게임 데이터 값 초기화
		nRand1 = rand() % 9 + 1;
		while (true)
		{
			nRand2 = rand() % 9 + 1;

			if (nRand2 != nRand1)
				break;
		}
		while (true)
		{
			nRand3 = rand() % 9 + 1;

			if (nRand3 != nRand1 % nRand3 != nRand2)
				break;
		}

		strike = 0; // 스트라이크 개수 초기화

		//게임 진행
		while (strike < 3) // 게임 클리어 조건
		{
			cout << "정답 : " << nRand1 << nRand2 << nRand3 << endl;

			cout << "첫번 째 숫자를 고르세요. (1 ~ 9) : ";
			cin >> nUser1;
			cout << "두번 째 숫자를 고르세요. (1 ~ 9) : ";
			cin >> nUser2;
			cout << "세번 째 숫자를 고르세요. (1 ~ 9) : ";
			cin >> nUser3;

			strike = ball = out = 0;

			if (nUser1 == nRand1)
				strike++;

			else if (nUser1 == nRand2 || nUser1 == nRand3)
				ball++;

			else
				out++;

			if (nUser2 == nRand2)
				strike++;

			else if (nUser2 == nRand1 || nUser2 == nRand3)
				ball++;

			else
				out++;

			if (nUser3 == nRand3)
				strike++;

			else if (nUser3 == nRand1 || nUser3 == nRand2)
				ball++;

			else
				out++;

			nCount++;

			cout << "스트라이크   : " << strike << endl
				 << "볼           : " << ball << endl
				 << "아웃         : " << out << endl;
			cout << "총 도전 횟수 : " << nCount << endl;
			cout << "==========================================" << endl;
			//system("pause");
		}




		//게임 클리어 후 새 게임 진행 여부
		char chYN;
		cout << "새 게임(y, n) : ";
		cin >> chYN;
		system("cls"); // 화면을 꺠끗하게 내용을 지워주는 명령어

		if (chYN == 'n')
			bGame = false;
	}

	system("pause");
	return 0;
}
