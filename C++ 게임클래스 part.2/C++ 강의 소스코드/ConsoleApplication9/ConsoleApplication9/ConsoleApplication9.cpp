// ConsoleApplication9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


/*
*----		----*		*****		*****
**---		---**		-****		****-
***--		--***		--***		***--
****-		-****		---**		**---
*****		*****		----*		*----
*/

int main()
{
	char szStar[4][5][5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i >= j)
				szStar[0][i][j] = '*';
			else
				szStar[0][i][j] = '-';
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i >= j)
				szStar[1][i][4 - j] = '*';
			else
				szStar[1][i][4 - j] = '-';
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i <= 4 - j)
				szStar[2][i][4 - j] = '*';
			else
				szStar[2][i][4 - j] = '-';
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i <= 4 - j)
				szStar[3][i][j] = '*';
			else
				szStar[3][i][j] = '-';
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				cout << szStar[i][j][k];
			}
			cout << endl;
		}
		cout << "=========================" << endl;
	}

	system("pause");

    return 0;
}