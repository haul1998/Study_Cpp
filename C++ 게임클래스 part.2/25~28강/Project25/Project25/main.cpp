#include "stdafx.h"
/*
// 구조제 (struct)와 클래스 (class)는 기본적인 형태는 같지만 private, public의 차이만 있을 뿐 나머지 공간은 같다.

struct tagPlayer        // 구조체 : 여러 가지 데이터들을 묶어서 관리할 수 있도록 사용하는 문법
{                       // 자료를 모아두는 형태로 사용된다.
    int a;

public:                 // 구조체는 기본 영역이 public 으로 되어있다 (공용 : 누구나 다 접근 가능한 영역)
    int b;

private:                // private 공간에 있는 것은 외부에서 접근이 불가능하다.
    int c;
};

class cPlayer         // 클래스 : 자동적으로 private 공간이 된다.
{
    
    int d;
    int e;
    int f;

public:
    
//int Function()
//{
//    return 30;
//}
    int Function();
};

int cPlayer::Function()
{
    return 30;
}

int FunctionPlus(int a, int b);

int main()
{
    //tagPlayer p1;
    //cPlayer p2;
    //p2.Function();

    return 0;
}


int FunctionPlus(int a, int b)
{
    return a + b;
}
*/