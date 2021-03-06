// Inheritance.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/*
클래스에서 상속이란?
부모 클래스로 부터 자식 클래스로 변수 또는 함수를 물려주는 시스템
*/

/*
virtual function (가상 함수)
C++ 는 다형성이라는 특성을 지원하기 위해 virtual 키워드를 제공 합니다.
부모 클래스 내에서 virtual로 선언 된 함수는 자식 클래스에서 재정의가 될 수 있습니다.
만약에 재정의를 하지 않고 호출을 한다면 부모의 함수가 호출이 되고
재정의를 했다면 재정의 된 자식의 클래스가 호출이 됩니다.
*/

class cWeapon	// 부모 클래스
{
protected:
	int		m_nAttDamage;	// 공격력
	int		m_nDurability;	// 내구도

public:
	virtual void Attack()	// 공격 - 가상함수
	{
		cout << "맨손 공격!! : " << m_nAttDamage << endl;
	}
	virtual void Defence()	// 방어 - 가상함수
	{
		cout << "방어 하기!!" << endl;
	}
};

class cSword : public cWeapon
{
public:
	void Attack() override
	{
		cout << "칼로 공격!! : " << m_nAttDamage << endl;
	}
	void Defence() override
	{
		cout << "칼로 방어!!" << endl;
	}
};

class cGun : public cWeapon
{
public:
	void Attack() override
	{
		cout << "총으로 공격!! : " << m_nAttDamage << endl;
	}
	void Defence() override
	{
		cout << "총으로 방어!!" << endl;
	}
};


int main()
{
	cWeapon* pWeapon = new cWeapon;

	pWeapon->Attack();
	pWeapon->Defence();
	delete pWeapon;

	cWeapon* pWeapon2 = new cSword;
	pWeapon->Attack();
	pWeapon->Defence();
	delete pWeapon;

	system("pause");

    return 0;
}