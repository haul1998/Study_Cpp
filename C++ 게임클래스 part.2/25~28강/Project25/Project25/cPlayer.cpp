#include "stdafx.h"
#include "cPlayer.h"

cPlayer::cPlayer()
{
	m_strName = "AAA";
	m_eState = P_IDLE;
	m_nLevel = 1;
	m_nExp = 0;

	m_eArmor = A_LIGHT;
	CalcMaxHp();		// 갑옷 정보를 불러옴으로서 최대 체력 정보를 갑옷 입은 상태의 정보로 불러온다.

	m_nCurrHp = m_nMaxHp;
	m_nAtt = 10;
}
cPlayer::~cPlayer()
{

}

void cPlayer::IncreaseExp(int Exp)		// cPlayer:: 이기 때문에 cPlayer에 해당하는 코드라 private에 해당하는 내용에 접근할 수 있다.
{
	// 현재 경험치 : 150 + 경험치 : 260 = 410 -> 5렙 증가
	m_nExp += Exp;
	if (m_nLevel * 100 < m_nExp)
	{
		m_nLevel = m_nExp / 100 + 1;
	}
}

void cPlayer::CalcMaxHp()
{
	switch (m_eArmor)
	{ 
		case A_LIGHT:
		{
			m_nMaxHp = 150;
		}
			break;
		case A_MEDIUM:
		{
			m_nMaxHp = 200;
		}
			break;
		case A_HEAVY:
		{
			m_nMaxHp = 300;
		}
			break;
		default:
		{
			m_nMaxHp = 100;
		}
			break;
	}
}

void cPlayer::CalcAttDamage()
{

}

