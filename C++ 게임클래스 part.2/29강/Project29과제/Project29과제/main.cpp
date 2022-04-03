#include "stdafx.h"

int nNum[10];

void Suffle();
int main()
{
	srand(time(NULL));
	rand();

	vector<int> vecInt;
	vector<int>::iterator iter;

	Suffle();
	
	for (int i = 0; i < 10; i++)
	{
		vecInt.insert(vecInt.begin(), 1, nNum[i]);
	}

	for (int i = 0; i < 9; i++)
	{
		if (vecInt[i] == 5)
		{
			vecInt.erase(vecInt.begin() + i);
		}
	}

	for (iter = vecInt.begin(); iter != vecInt.end(); iter++)
	{
		cout << (*iter) << endl;
	}
	system("pause");
	return 0;
}

void Suffle()
{
	for (int i = 0; i < 10; i++)
	{
		nNum[i] = i + 1;
	}

	for (int i = 0; i < 100; i++)
	{
		int nSrc = rand() % 10;
		int nDest = rand() % 10;

		int Temp = nNum[nSrc];
		nNum[nSrc] = nNum[nDest];
		nNum[nDest] = Temp;
	}
}