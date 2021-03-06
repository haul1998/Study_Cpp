// TextRPG.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "cPlayer.h"
#include "cMonster.h"

void Town(cPlayer* player, bool& playing);
void Store(cPlayer* player);
void Dungeon(cPlayer* player);

int main()
{
	bool		isPlaying = true;
	int			nSelect;
	cPlayer*	pPlayer = new cPlayer();
	pPlayer->SetPlace(EP_TOWN);

	while (isPlaying)
	{
		system("cls");

		cout << "이름	: " << pPlayer->GetName().c_str() << endl;
		cout << "레벨	: " << pPlayer->GetLevel() << endl;
		cout << "경험치	: " << pPlayer->GetExp() << endl;
		cout << "체력	: " << pPlayer->GetCurrHp() << " / " << pPlayer->GetMaxHp() << endl;
		cout << "공격력	: " << pPlayer->GetAttDamage() << endl << endl;

		cout << "현재 위치 : ";
		switch (pPlayer->GetPlace())
		{
		case EP_QUIT:
			system("cls");
			cout << "게임을 종료 합니다." << endl;
			isPlaying = false;
			break;
		case EP_TOWN:
			cout << "마을" << endl;
			Town(pPlayer, isPlaying);
			break;
		case EP_STORE:
			cout << "상점" << endl;
			Store(pPlayer);
			break;
		case EP_DUNGEON:
			cout << "던전" << endl;
			Dungeon(pPlayer);
			break;
		}

		Sleep(2000);
	}

	delete pPlayer;

	system("pause");

    return 0;
}

void Town(cPlayer* player, bool& playing)
{
	int nSelect;

	cout << "1.여관 2.상점 3.모험을 떠나자~ (0.게임 종료) : ";
	cin >> nSelect;

	if (nSelect == 1)
	{
		cout << "휴식을 취합니다~ HP 회복!" << endl;
		cout << "마을로 돌아 갑니다." << endl;
		player->SetMaxHp();
		player->SetPlace(EP_TOWN);
	}
	else if (nSelect == 2)
	{
		cout << "상점으로 이동 합니다." << endl;
		player->SetPlace(EP_STORE);
	}
	else if (nSelect == 3)
	{
		cout << "던전으로 이동 합니다." << endl;
		player->SetPlace(EP_DUNGEON);
	}
	else if (nSelect == 0)
	{
		player->SetPlace(EP_QUIT);
	}
	else
	{
		cout << "제대로 입력해라!!!!" << endl;
	}
}

void Store(cPlayer* player)
{
	cout << "상점에 주인이 없습니다. 마을로 돌아 갑니다." << endl;
	player->SetPlace(EP_TOWN);
}

void Dungeon(cPlayer* player)
{
	cout << "던전에 입장 했습니다. 몬스터와 전투를 시작 합니다." << endl;

	cMonster* pMonster = new cMonster("오우거", 50, 20, 200);

	cout << "몬스터 이름 : " << pMonster->GetName() << endl;
	cout << "몬스터 체력 : " << pMonster->GetHp() << endl;
	cout << "몬스터 기본 공격력 : " << pMonster->GetAttDamage() << endl;
	cout << "============================================" << endl << endl;
	Sleep(2000);

	while (true)
	{
		int nDamage = player->GetAttDamage() + player->GetExDamage();
		cout << "플레이어가 공격 합니다. : " << nDamage << endl;
		pMonster->TakeDamage(nDamage);
		Sleep(500);

		if (pMonster->GetHp() <= 0)
		{
			cout << "몬스터를 처치 했습니다." << endl;
			cout << pMonster->GetExp() << " 경험치를 획득 했습니다." << endl;
			player->IncreaseExp(pMonster->GetExp());
			break;
		}

		nDamage = pMonster->GetAttDamage() + pMonster->GetExDamage();
		cout << "몬스터가 공격 합니다. : " << nDamage << endl;
		player->TakeDamage(nDamage);
		Sleep(500);

		if (player->GetCurrHp() <= 0)
		{
			cout << "플레이어가 체력이 없습니다. 마을로 도망 갑니다." << endl;
			break;
		}
	}

	Sleep(2000);
	player->SetPlace(EP_TOWN);

	delete pMonster;
}