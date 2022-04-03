#include <iostream>
#include "pch.h"


int main()
{
    int a = 20;
    int b = 5;
    int c = 3;

    if (a == 20 && a > 10)
        cout << "a는 20과 같다." << endl;

    else if (a < 10)
        cout << "a는 10보다 작다." << endl;

    else
        cout << "a는 10보다 크고 20과 같지 않다." << endl;
    system("pause");


    int x;
    int y;
    int nSelect;

    cout << "x의 값을 입력하시오. : ";
    cin >> x;
    cout << "y의 값을 입력하시오. : ";
    cin >> y;
    cout << "=======================" << endl;
    cout << "1. 덧셈, 2. 뺄셈, 3. 곱하기, 4. 나누기 : ";
    cin >> nSelect;
    
    cout << "결과 :";

    if (nSelect == 1)
        cout << x + y << endl;

    else if (nSelect == 2)
        cout << x - y << endl;

    else if (nSelect == 3)
        cout << x * y << endl;

    else if (nSelect == 4)
        cout << x / y << endl;

    system("pause");
}