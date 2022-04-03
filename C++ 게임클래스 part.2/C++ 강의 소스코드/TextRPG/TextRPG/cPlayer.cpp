#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
{
	m_strName = "우주최강캐릭터";
	m_eState = P_IDLE;

	m_nExp = 0;
	m_nLevel = 1;

	m_eArmor = A_LIGHT;
	CalcMaxHp();

	m_nCurrHp = m_nMaxHp;
	m_nAtt = 5;
}


cPlayer::~cPlayer()
{
}

void cPlayer::IncreaseExp(int exp)
{
	// 현재 경험치가 150(2) + 260 = 410 => 5렙

	m_nExp += exp;

	if (m_nLevel * 100 < m_nExp)
		m_nLevel = m_nExp / 100 + 1;
}

void cPlayer::CalcMaxHp()
{
	switch (m_eArmor)
	{
	case A_LIGHT:
		m_nMaxHp = 150;
		break;
	case A_MEDIUM:
		m_nMaxHp = 200;
		break;
	case A_HEAVY:
		m_nMaxHp = 300;
		break;
	default:
		m_nMaxHp = 100;
		break;
	}
}

void cPlayer::CalcAttDamage()
{

}
