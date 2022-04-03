#pragma once
// 이 곳에서 모든 클래스를 관리할 예정
// 인벤토리는 플레이어가 가지고 있기 때문에 이곳에서 선언하지 않음
// cStock 또한 cShop이 상속을 받아서 선언하지 않음
#include "stdafx.h"
#include "cPlayer.h"
#include "cTown.h"
#include "cShop.h"

class cMainGame
{
private:
	cPlayer*	m_pPlayer; 
	LOCATION	m_eCurrLoc;		// 현재 캐릭터의 위치 정보
	
	cTown*		m_pTown;
	cShop*		m_pShop;

public:
	cMainGame();
	~cMainGame();

	void MainPlay();
};

