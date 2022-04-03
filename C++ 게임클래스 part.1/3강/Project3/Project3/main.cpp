#include "stdafx.h"
#include <iostream>

/*
조건문
  -  if, else if, else

관계 연산자 
  -  == < > <= >= !=

논리 연산자
  -  &&(AND 연산자) : AND 연산자로 연결된 조건이 모두 참이여야 최종 결과가 참이 된다,
  -  || (OR 연산자) : OR 연산자로 연결된 조건 중 하나만 참이면 최종 결과가 참이다.

& 의 경우 비트 연산 처리이기에 비교 연산에서는 2번씩 적어줘야한다.

*/

void main()
{
    int nA = 20;
    int nB = 5;
    int nC = 3;
    
    /*
    if (nA > 10)
    {
        cout << "nA의 값은 10보다 크다." << endl;
    }

    else if (nA != 20)
    {
        cout << "nA의 값은 20과 같지 않다." << endl;
    }

    else if (nA == 10) // 개수 제한이 없다
    {
        cout << "nA의 값은 10과 같다." << endl;
    }
    */

    /*
    if (nA < 10 && nA > 5)
    {
        cout << "nA의 값은 5보다크고 10보다 작다." << endl;
        cout << "출력!!" << endl;
    }
    else
    {
        cout << "nA의 값은 10보다 작다." << endl;
    }
    */
    
    int x;
    int y;
    int nSelect;

    cout << "x의 값을 입력하세요 : ";
    cin >> x;
    cout << "y의 값을 입력하세요 : ";
    cin >> y;
    cout << "====================" << endl;
    cout << "1. 덧셈, 2. 뺄셈, 3. 곱셈, 4. 나눗셈 : ";
    cin >> nSelect;

    cout << "결과 : ";

    if (nSelect == 1)
    {
        cout << x + y << endl;
    }

    else if (nSelect == 2)
    {
        cout << x - y << endl;

    }

    else if (nSelect == 3)
    {
        cout << x * y << endl;
    }

    else if (nSelect == 4)
    {
        cout << x / y << endl;

    }

    else
    {
        cout << "제대로 된 값이 아닙니다." << endl;
    }
    system("pause");
}