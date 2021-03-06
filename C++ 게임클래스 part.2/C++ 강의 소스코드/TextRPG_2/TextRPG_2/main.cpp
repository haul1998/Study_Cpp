// TextRPG_2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "cMainGame.h"

// 메인 게임 클래스 : 전체 게임 클래스들을 관리 해주는 클래스
// 플레이어 클래스
// 스톡 클래스 : 인벤토리 및 상점의 부모 클래스 - 아이템 관리를 해주는 클래스
// 인벤토리 클래스 (스톡) : 플레이어가 보유 중인 아이템을 관리 해주는 클래스
// 상점 클래스 (스톡) : 상점의 아이템을 관리 해주는 클래스, 가상의 상점을 구현
// 타운 클래스 : 가상의 마을을 구현

int main()
{
	// 콘솔창 사이즈
	system("mode con: cols=96 lines=27");

	cMainGame* pMg = new cMainGame;
	bool isPlaying = true;

	while (isPlaying)
	{
		pMg->MainPlay();

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) // esc 키를 눌렀을 때
			isPlaying = false;
	}

    return 0;
}

