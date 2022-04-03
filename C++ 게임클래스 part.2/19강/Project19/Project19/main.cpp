#include "stdafx.h"

// 구조체 : 여러가지 역할을 하나로 묶어서 관리할 수 있게 해준다.
// 구조체 변수명은 보통 tag를 붙이는 편이다.
struct tagMonster   // 몬스터 구조체
{
    string strName; // 몬스터 이름
    int nHP;        // 체력
    int nMP;        // 마나
    int nAtt;       // 공격력
    int nDef;       // 방어력
};
int main()
{
    srand(time(NULL));
    rand();
    // char과 다르게 string은 문자열을 담을 수 있다.
    tagMonster stMonster;   // 구조체의 변수 경우 struct 이기에 st를 붙힌다.
 
    // 구조체 값 설정
    stMonster.strName = "오우거";
    stMonster.nHP = 100;
    stMonster.nMP = 30;
    stMonster.nAtt = 10;
    stMonster.nDef = 5;

    cout << stMonster.strName.c_str() << "의 공격력은 " << stMonster.nAtt << "이다." << endl;  // cout으로 호출할 때 c_로 함수 호출을 해줘야한다.

    tagMonster stMonster1 = {"뱀파이어", 50, 100, 25, 1};   // 구조체 선언 및 초기화
    
    cout << stMonster1.strName.c_str() << "의 공격력은 " << stMonster1.nAtt << "이다." << endl;

    //tagMonster* pMonster = new tagMonster;
    tagMonster* pMonster;

    pMonster = new tagMonster; // 필요할 때 메모리에 할당해서 사용할 수도 있다.
    pMonster->strName = "트롤"; // 구조체를 포인터로 선언했을 시 접근할 때 -> 로 사용한다.
    pMonster->nHP = 100;

    delete pMonster;

    tagMonster stMonsterArray[10];  // 구조체도 변수들처럼 배열로 선언하여 사용이 가능하다.
    for (int i = 0; i < 10; i++)
    {
        stMonsterArray[i].strName = "오우거";
        stMonsterArray[i].nHP = 100 + rand() % 51;  // HP가 100 ~ 150 사이의 체력으로 지정된다.
        stMonsterArray[i].nMP = 30;
        stMonsterArray[i].nAtt = 10;
        stMonsterArray[i].nDef = 5;
    }

    tagMonster* aMonster = new tagMonster[10];
    aMonster[0].strName = "뱀파이어2";
    aMonster[1].strName = "뱀파이어3";

    delete[] aMonster;  // 배열로 만든 포인터 구조체를 제거할 때 delete에 []를 붙혀서 사용한다.

    tagMonster* aMonster2;                          // 몬스터를 포인터로 선언
    int nNumberOfMonster = 10 + rand() % 11;        // 생성할 몬스터 숫자를 랜덤으로 결정 (10 ~ 20)
    aMonster2 = new tagMonster[nNumberOfMonster];   // 정해진 수만큼 몬스터 구조체 수를 할당

    for (int i = 0; i < nNumberOfMonster; i++)
    {
        aMonster2[i].strName = "던전형 몬스터";
        aMonster2[i].nHP = 100 + rand() % 51;
        aMonster2[i].nMP = 30;
        aMonster2[i].nAtt = 10 + rand() % 5;
        aMonster2[i].nDef = 5;
    }
    cout << "소환 몬스터 수 : " << nNumberOfMonster << endl;

    for (int i = 0; i < nNumberOfMonster; i++)
    {
        cout << "몬스터 종류 : " << aMonster2[i].strName.c_str() << endl;
        cout << "몬스터 체력 : " << aMonster2[i].nHP << endl;
        cout << "몬스터 공격력 : " << aMonster2[i].nAtt << endl;
        cout << endl;
    }

    system("pause");
    return 0;
}
