// ConsoleApplication4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	srand(time(NULL));
	rand();

	// i = i + 2;
	/*
		1 x 1 = 1	2 x 1 = 2	3 x 1 = 3
		1 x 2 = 2	2 x 2 = 4	3 x 2 = 6
		...
		...

		4 x 1 = 4	...
		...
		...

		7 x 1 = 7 
		...
		7 x 9 = 63
	*/

	//for (int i = 0; i < 9; i += 3)			// 총 9단을 출력한다. (3단씩 묶어서)
	//{
	//	for (int j = 1; j <= 9; j++)		// x 1 ~ 9 까지 출력
	//	{
	//		for (int k = 1; k <= 3; k++)	// 3단씩 묶어서 줄 단위로 출력
	//		{
	//			cout << i + k << " x " << j << " = " << (i + k) * j << "\t\t";
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//}

	for (int i = 1; i <= 9; i += 3)		// 3단씩 묶어서 출력
	{
		for (int j = 1; j <= 9; j++)	// x 1 ~ 9
		{
			cout << i + 0 << " x " << j << " = " << (i + 0) * j << "\t\t";
			cout << i + 1 << " x " << j << " = " << (i + 1) * j << "\t\t";
			cout << i + 2 << " x " << j << " = " << (i + 2) * j << endl;
		}
		cout << endl;
	}

	system("pause");

    return 0;
}

