#pragma once
#include "stdafx.h"

// ���, ����, �̵�
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
	string m_strName;		// ĳ���� �̸�
	E_PSTATE m_eState;		// ĳ���� ����		// ��� ������� �ǹ̷� �տ� m_ �� ������ �������� �����Ѵ�.
	int  m_nLevel;			// ĳ���� ����
	int m_nExp;				// ĳ���� ����ġ
	int m_nMaxHp;			// �ִ� ü��
	int m_nCurrHp;			// ���� ü��
	int m_nAtt;				// ���ݷ�

	E_ARMOR m_eArmor;		// ���� ���� ��
	E_PLACE m_eCurrPlace;	// ���� ĳ������ ���
	


public:
	cPlayer();				// Ŭ���� ���� �� ����� ������
	~cPlayer();				// Ŭ���� ������ �� �� ���׵Ǵ� �ı���

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

	// �÷��� ���� ����
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

