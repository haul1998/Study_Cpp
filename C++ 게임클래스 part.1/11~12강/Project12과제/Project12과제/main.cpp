#include "stdafx.h"

int nCards[12];

void suffle()
{
    int nSrc = rand() % 12;
    int nDest = rand() % 12;

    int Temp = nCards[nSrc];
    nCards[nSrc] = nCards[nDest];
    nCards[nDest] = Temp;
}

int main()
{
    srand(time(NULL));
    rand();

    suffle();

    for (int i = 0; i < 12; i++)
    {
        cout << nCards[i] << " ";
    }
    system("pause");
    return 0;
}