#include "stdafx.h"

int main()
{
	srand(time(NULL));
	rand();

	for(int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 0; k < 9; k += 3)
			{
				cout << i + k << " * " << j << " = " << (i + k) * j << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}