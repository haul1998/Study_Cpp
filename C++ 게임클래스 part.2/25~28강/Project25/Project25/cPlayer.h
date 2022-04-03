#pragma once
#include "stdafx.h"

// 대기, 전투, 이동
enum E_ARMOR
{
	A_EMPTY, A_LIGHT, A_MEDIUM, A_HEAVY
};

enum E_PSTATE
{
	P_IDLE, P_FIGHT, P_WALK
};

class cPlayer
{
private:
	string m_strName;		// 캐릭터 이름
	E_PSTATE m_eState;		// 캐릭터 상태		// 멤버 변수라는 의미로 앞에 m_ 을 붙혀서 변수명을 선언한다.
	int  m_nLevel;			// 캐릭터 레벨
	int m_nExp;				// 캐릭터 경험치
	int m_nMaxHp;			// 최대 체력
	int m_nCurrHp;			// 현재 체력
	int m_nAtt;				// 공격력

	E_ARMOR m_eArmor;		// 현재 장착 방어구
	E_PLACE m_eCurrPlace;	// 현재 캐릭터의 장소
	


public:
	cPlayer();				// 클래스 선언 시 생기는 생성자
	~cPlayer();				// 클래스 삭제가 될 떄 실항되는 파괴자

	string GetName()
	{
		return m_strName;
	}
	E_PSTATE GetState()
	{
		return m_eState;
	}
	int GetLevel()
	{
		return m_nLevel;
	}
	int GetExp()
	{
		return m_nExp;
	}
	void SetExp(int exp)
	{
		m_nExp == exp;
	}
	int GetMaxHP()
	{
		return m_nMaxHp;
	}
	int GetCurrHp()
	{
		return m_nCurrHp;
	}
	void SetMaxHp()
	{
		m_nCurrHp = m_nMaxHp;
	}
	int GetAttDamage()
	{
		return m_nAtt;
	}
	int GetExDamage()
	{
		return rand() % 11;
	}
	int TakeDamage(int damage)
	{
		return m_nCurrHp -= damage;
	}

	// 플레이 겟터 셋터
	E_PLACE GetPlace()
	{
		return m_eCurrPlace;
	}
	void SetPlace(E_PLACE place)
	{
		m_eCurrPlace = place;
	}

	void IncreaseExp(int Exp);
	void CalcMaxHp();
	void CalcAttDamage();
};

