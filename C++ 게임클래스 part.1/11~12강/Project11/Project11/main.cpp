#include "stdafx.h"

int main()
{
	int nArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++)
	{
		nArray[i] = i + 1;
	}

	int nDArray[10][5];
	int nDArray2[10][5] = { {0, } };  // 전부 0으로 초기화 시키고 싶을 때 간단하게 입력하는 법

	/*
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			nDArray[i][j] = (j + 1) + i * 5;
			cout << nDArray[i][j] << " , ";
		}
	}
	*/

	//for (int i = 0; i < 50; i++)
	//{
	//	nDArray[i / 5][i % 5] = ((i / 5) * 5) + (i % 5 + 1); // = 뒷부분의 순서를 거꾸로도 가능
	//}
	//
	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		cout << nDArray[i][j] << " , ";
	//	}
	//}


	// ===============================여기부터 첫번째 과제===============================

	/*1번    2번     3번     4번     5번     6번     7번
	*****	-----	*****	-****	****-	-----	*****
	*****	*****	*****	-****	****-	-***-	*---*
	*****	*****	*****	-****	****-	-***-	*---*
	*****	*****	*****	-****	****-	-***-	*---*
	*****	*****	-----	-****	****-	-----	*****
	*/

	/*
	char szStar[5][5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 0)
			{
				szStar[i][j] = '-';
			}
			else
			{
				szStar[i][j] = '*';
			}
			cout << szStar[i][j];
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 4)
			{
				szStar[i][j] = '-';
			}
			else
			{
				szStar[i][j] = '*';
			}
			cout << szStar[i][j];
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j == 0)
			{
				szStar[i][j] = '-';
			}
			else
			{
				szStar[i][j] = '*';
			}
			cout << szStar[i][j];
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j == 4)
			{
				szStar[i][j] = '-';
			}
			else
			{
				szStar[i][j] = '*';
			}
			cout << szStar[i][j];
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 0 || i == 4 || j == 0 || j == 4)
			{
				szStar[i][j] = '-';
			}
			else
			{
				szStar[i][j] = '*';
			}
			cout << szStar[i][j];
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 0 || i == 4 || j == 0 || j == 4)
			{
				szStar[i][j] = '*';
			}
			else
			{
				szStar[i][j] = '-';
			}
			cout << szStar[i][j];
		}
		cout << endl;
	}

	cout << endl;
	*/

	// ===============================두번째 과제===============================

	/*
	  1번    2번     3번     4번
	*----	----*	*****	*****
	**---	---**	-****	****-
	***--	--***	--***	***--
	****-	-****	---**	**---
	*****	*****	----*	*----
	*/

	char nStar[5][4][5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == 0)
			{
				for (int k = 0; k < 5; k++)
				{
					if (k <= i)
					{
						cout << "*";
					}
					else
					{
						cout << '-';
					}
				}
				cout << "\t";

			}

			else if (j == 1)
			{
				for (int k = 0; k < 5; k++)
				{
					if (4 - k >= i + 1)
					{
						cout << "-";
					}
					else
					{
						cout << '*';
					}
				}
				cout << "\t";

			}

			else if (j == 2)
			{
				for (int k = 0; k < 5; k++)
				{
					if (i <= k)
					{
						cout << "*";
					}
					else
					{
						cout << '-';
					}
				}
				cout << "\t";
			}

			else 
			{
				for (int k = 0; k < 5; k++)
				{
					if (4 - k >= i)
					{
						cout << "*";
					}
					else
					{
						cout << '-';
					}
				}
				cout << "\t";

			}

		}
		cout << endl;
	}

	system("pause");
	return 0;
}