// ConsoleApplication3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int main()
{
	//int nA, nB;

	//for (int i = 0; i < 5; i++)
	//{
	//	// 1. 변수 선언 및 초기화
	//	// 2. 조건 검사 (조건이 맞지 않으면 포문을 빠져나간다.)
	//	// 3. 알고리즘 실행
	//	// 4. 증감값 적용
	//	// 5. 2 ~ 4번 반복

	//	cout << " : ";
	//	cin >> nA;
	//	cout << " : ";
	//	cin >> nB;

	//	cout << "덧셈 결과 : " << nA + nB << endl;
	//}

	int nA, nB;
	bool isContinue;

	while (true)
	{
		cout << " : ";
		cin >> nA;
		cout << " : ";
		cin >> nB;

		cout << "덧셈 결과 : " << nA + nB << endl;
		cout << "0. 종료, 1. 계속 : ";
		cin >> isContinue;

		if (isContinue == false)
			break;
	}

	system("pause");

    return 0;
}

