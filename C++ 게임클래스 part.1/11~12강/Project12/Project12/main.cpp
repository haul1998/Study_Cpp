#include "stdafx.h"

// 함수의 가독성이 좋아지기에 사용하기 좋다.
// ex) 몬스터를 공격했을 때, 플레이어의 공격력과 무기의 공격력을 합산하고 몬스터의 방어력을 뺏을 때 들어가는 데미지를 계산할 때 사용하기 좋다.

int nCards[52];  // 전역 변수 : 함수 밖에서 선언하는 변수, 모든 함수에서 사용이 가능하다. 함부로 사용하면 안된다.

int Add(int a, int b)
{
    nCards[3] = 3;

    return a + b;
}

int Subtract (int a, int b)
{
    nCards[4] = 5;
    return a - b;
}

int DamageToMonster(int attack, int weapon, int monsterArmor) // ( ) 안에 있는 매개 변수의 인자값(int) 으로 넣어줘야 다른 함수에서 사용이 가능하다.
{
    int addDamage = 10; // 지역 변수

    return attack + weapon - monsterArmor;
}

void Suffle()
{
    int nSrc = rand() % 52;
    int nDest = rand() % 52;

    int Temp = nCards[nSrc];
    nCards[nSrc] = nCards[nDest];
    nCards[nDest] = Temp; // 셔플한 것을 지연 변수가 아닌 전역 변수로 만들어주면 생성 가능
}

// 메인 함수
int main()
{
    srand(time(NULL));
    rand();

    int nA = 10, nB = 5;

    cout << Add(nA, nB) << endl;
    cout << Subtract(6, 3) << endl;
    
    cout << DamageToMonster(5, 10, 3) << endl;

    // cout << addDamage << endl; // 해당하는 지역의 변수가 아니기에 사용이 불가능하다.

    // == 플레이 ==
    int nSrc = rand() % 52;
    int nDest = rand() % 52;

    int Temp = nCards[nSrc];
    nCards[nSrc] = nCards[nDest];
    nCards[nDest] = Temp;

    // ==새 카드 필요==
    Suffle(); // 코드를 반복해서 사용하는게 아닌 지역 변수를 새로 호출해주는게 간결하다.

    for (int i = 0; i < 52; i++)
    {
        cout << nCards[i] << endl;
    }
    system("pause");
    return 0;
}