#include "stdafx.h"

// 배열 : 순차적인 공간을 할당해서 데이터를 지정하는 방식
// 셔플 : 랜덤하게 섞고 같은 값이 나오지 않는다.

int main()
{
    //int nData = 10;
    //int aData[3] = {1, 2, 3};
    // 위와 아래는 같은 결과물을 가지는 배열
    //aData[0] = 1;
    //aData[1] = 2;
    //aData[2] = 3;
	
	/*
	int nData[9];
	for (int i = 0; i < 10; i++)
	{
		nData[i] = i + 1;
	}
	
	for (int i = 0; i < 100; i++)
	{
		int nSrc = rand() % 9;  // 소스 인덱스 번호
		int nDest = rand() % 9; // 데스트 인덱스 번호
		
		int nTemp = nData[nSrc];
		nData[nSrc] = nData[nDest];
		nData[nDest] = nTemp;
	}

	for (int i = 0; i < 10; i++)
	{
		nData[i] = i + 1;+-
	}
	*/
	srand(time(NULL));
	rand();

    int nRand[9];
    int nUser[3];
    int strike, ball, out;
    int nCount;
    bool bGame = true;

	cout << "==========================================" << endl;
	cout << "게임 규칙" << endl;
	cout << "실제 게임과 최대한 비슷하게 구현하여 " << endl << "숫자 3개를 올바른 순서로 모두 맞추거나" << endl << "도전 횟수 10회를 넘기면 게임이 끝납니다." << endl;
	cout << "==========================================" << endl;

	while (bGame)
	{
		nCount = 0;
		strike = ball = out = 0;

		//int nData[9];
		
		for (int i = 0; i < 9; i++) // 1 ~ 9 까지의 슬롯 생성
		{
			nRand[i] = i + 1;
			//cout << nRand[i] << endl;
		}

		for (int i = 0; i < 100; i++) // 100회 셔플
		{
			int nSrc = rand() % 9; // nSrc에 1 ~ 9의 숫자를 넣기
			int nDest = rand() % 9; //nDest에 1 ~ 9의 숫자를 넣기
			
			int Temp = nRand[nSrc]; //nData에 nSrc 값을 넣어서 Temp에 집어넣기
			nRand[nSrc] = nRand[nDest]; // 비어있는 nSrc에 nDest를 집어넣기
			nRand[nDest] = Temp; // 비어있는 nDest에 Temp를 집어넣기
								// 이 과정을 반복해서 숫자를 무작위로 셔플
		}

		strike = 0; // 스트라이크 개수 초기화

		//게임 진행
		while (strike < 3 || nCount < 11) // 게임 클리어 조건
		{
			cout << "정답 : " << nRand[0] << nRand[1] << nRand[2] << endl;

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
				else if (nUser[i] == nRand[i] || nUser[(i + 1) % 3] == nRand[(i + 2) % 3])
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
				cout << "CLEAR" << endl;
				break;
			}
			else if (nCount == 10)
			{
				cout << "FAIL" << endl;
				break;
			}
			//system("pause");
		}

		//게임 클리어 후 새 게임 진행 여부
		system("cls"); // 화면을 꺠끗하게 내용을 지워주는 명령어
		cout << "==========================================" << endl;
		cout << "정답 : " << nRand[0] << nRand[1] << nRand[2] << endl;
		cout << "총 도전 횟수 : " << nCount << endl;

		char chYN;
		cout << "새 게임(y, n) : ";
		cin >> chYN;
		system("cls"); // 화면을 꺠끗하게 내용을 지워주는 명령어

		if (chYN == 'n' || chYN == 'N')
		{
			bGame = false;
		}
		else if (chYN == 'y' || chYN == 'Y')
		{
			bGame = true;
		}	
		else
		{
			cout << "잘못입력하셨습니다." << endl;
			bGame = false;
		}
	}

    system("pause");
    return 0;
}