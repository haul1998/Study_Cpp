#include "stdafx.h"

/*
상속이란?
부모 클래스로부터 자식 클래스로 변수 또는 함수를 물려주는 시스템
*/

/*
virtual 키워드로 변수, 함수를 만들 수 있고, 가상변수, 가상함수라고 할 수 있다.
virtual function (가상 함수)
C++는 다형성이라는 특성을 지원하기 위해 virtual 키워드를 제공한다.
부모클래스 내에서 virtual로 선언된 함수는 자식 클래스에서 재정의가 될 수 있다.
예) virtual void Attak()     <- 이 경우 Attack 함수는 가상 함수가 된다.

만약에 재정의하지 않고 호출을 할 경우 부모의 함수가 호출이 된다.
재정의를 할 경우 재정의된 자식의 클래스가 호출이 된다.

상속을 사용하는 이유는 다형성이라는 특성을 활용하기 위함이다.
*/


class cWeapon   // 부모 클래스
{
                // private      (개인 공간)     : 해당 클래스 내부에서만 접근 가능
                // protected    (보호된 공간)   : 상속 받은 자식 클래스에서도 접근 가능
                // puhblic      (공유 공간)     : 외부 어디에서든 접근 가능
//private:
//    int m_nTest;
protected:      // private와 public의 중간 / 외부에서는 접근이 안되지만 자식 클래스를 통해서 접근이 가능하다.
    int m_nAttDamage;       // 데미지
    int m_nDurability;      // 내구도

public:
    virtual void Attack()           // 공격하기 - 가상 함수
    {
        cout << "맨손 공격!!" << endl;
    }
    virtual void Defence()          // 방어하기 - 가상 함수
    {
        cout << "방어하기!!" << endl;
    }

    //int GetTest()           // 이런 식으로 정보를 가져올 수도 있다.
    //{
    //    return m_nTest;
    //}
    //void SetTest(int test)
    //{
    //    m_nTest = test;
    //}
};

class cSword : public cWeapon       // 자식 클래스 : 부모 클래스  / : = 상속
{
    /*
    void setAttDamage()             // void setAttDamage(다른 이름도 가능)를 이용하면 클래스를 통해 protected 공간에 있는 변수에 접근이 가능하다.
    {
        m_nAttDamage;
    }
    */
public:
    void Attack()   override          // virtual 사용 시 자식 클래스의 재정의를 한 후 표시로 override를 기입하고 ; 를 뺍니다.
    {
        cout << "칼로 공격!!" << endl;
    }
    
    void Defence()  override
    {
        cout << "칼로 방어!!" << endl;
    }
};

class cGun : public cWeapon
{
public:
    void Attack()   override
    {
        cout << "총으로 공격!!" << endl;
    }

    void Defence()  override
    {
        cout << "총으로 방어!!" << endl;
    }
};

int main()
{
    //sword.GetTest();
    //sword.SetTest(30);

    cWeapon weapon;
    weapon.Attack();
    weapon.Defence();
    cout << endl;

    cSword sword;
    sword.Attack();
    sword.Defence();
    cout << endl;

    cGun gun;
    gun.Attack();
    gun.Defence();
    cout << endl;


    cWeapon* pWeapon = new cWeapon;

    pWeapon->Attack();
    pWeapon->Defence();
    cout << endl;

    delete pWeapon;


    pWeapon = new cGun;
    
    pWeapon->Attack();
    pWeapon->Defence();
    cout << endl;

    delete pWeapon;

    system("pause");
    return 0;
}