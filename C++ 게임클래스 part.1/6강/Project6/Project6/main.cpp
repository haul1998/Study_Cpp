#include "stdafx.h"

int main()
{
	srand(time(NULL));
	rand();

	/*
	for (int i = 0; i < 3; i++)
	{
		//cout << i << endl;

		for (int j = 0; j < 3; j++) // 이중 for문 사용 시 변수 이름을 중복해서 쓰지 않는다.
		{
			cout << j + (i * 3) << endl;
		}
	}
	*/

	/*
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << "\t";
		}
		cout << endl;
	}
	*/
	// \t를 사용하면 줄간격 tab이 들어간다.

	/*
	for (int i = 0; i < 9; i += 3)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 1; k <= 3; k++)
			{
				cout << k + i << " * " << j << " = " << (k + i) * j << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	*/

	for (int i = 1; i <= 9; i+= 3)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i + 0 << " * " << j << " = " << (i + 0) * j << "\t\t";
			cout << i + 1 << " * " << j << " = " << (i + 1) * j << "\t\t";
			cout << i + 2 << " * " << j << " = " << (i + 2) * j << endl;
		}
		cout << endl;
	}


	system("pause");
	return 0;
}