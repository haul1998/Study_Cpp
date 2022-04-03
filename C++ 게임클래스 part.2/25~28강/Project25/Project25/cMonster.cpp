#include "stdafx.h"
#include "cMonster.h"

cMonster::cMonster()
{
	m_strName = "슬라임";
	m_nHp = 50;
	m_nAtt = 5;				// 5 ~ 15의 공격력 (공격할 때 추가 데미지(GetExDamage())를 넣을 예정)
	m_nExp = 20;
}
// 이 둘은 서로 다른 블럭인데 왜 서로 작용이 되는가
cMonster::cMonster(string name, int hp, int att, int exp)
{
	m_strName = name;
	m_nHp = hp;
	m_nAtt = att;
	m_nExp = exp;
}

cMonster::~cMonster()
{
}
