#include "stdafx.h"

void Suffle(int *arrData)  // 포인터를 이용하여 다른 지역 함수에 있는걸 접근할 수 있다.
{
    int nSrc;
    int nDest;
    int Temp;

    for (int i = 0; i < 100; i++)
    {
        nSrc = rand() % 10;
        nDest = rand() % 10;
        
        Temp = arrData[nSrc];
        arrData[nSrc] = arrData[nDest];
        arrData[nDest] = Temp;
    }
}
/*
int Add(int a, int b)
{
    a += 10;
    b -= 5;
    return a + b;
}

int Add2(int* a, int* b)  //함수의 매개 변수를 포인터로 받으면 변경이 가능하다.
{
    *a += 10;
    *b -= 5;
    return *a + *b;
}
*/
/*
포인터란?
주소값을 가리키는 값이다.
*/

int main()
{
    srand(time(NULL));
    rand();

    /*
    int nA, nB, nC;

    //int* pA = &nA;    // 포인터 설정이 되어있는 함수, 해당 값에 정수값을 넣으면 오류가 난다. 변수의 메모리 주소값만 받을 수 있다.
    int* pA = new int;  // new 연산을 통해서 메모리 공간을 할당한다.
    int* pB = new int;  // * 은 변수가 그 할당 된 메모리 공간을 가리킨다.
    int pC;

    *pA = 10;
    *pB = 5;

    cout << pA << endl;
    cout << pB << endl;

    pC = Add2(pA, pB);
    cout << pC << endl;

    nA = 10;
    nB = 5;
    nC = Add(nA, nB);
    
    cout << nA << " , " << nB << endl;
    cout << nC << endl;

    cout << &nA << endl;  // 변수 앞에 &를 붙히면 해당 메모리에 할당된 주소값이 출력된다. 즉, 주소값을 출력해달라는 의미이다.

    // 사용이 끝난 다음에 해제를 하지 않으면 메모리 누수가 발생한다.
    delete pA;
    delete pB;
    */

    int nArray[10]; // nArray는 배열이 할당된 첫번째 주소값을 가르킨다.
                    // nArray는 가르키는 주소값 + 0
                    // nArray는 가르키는 주소값 + 1  (선언된 변수의 크기에 따라 달라진다.)

    for (int i = 0; i < 10; i++)
    {
        nArray[i] = i + 1;
    }
    
    Suffle(nArray);

    for (int i = 0; i < 10; i++)
    {
        cout << nArray[i] << endl;
    }

    system("pause");

    return 0;
}