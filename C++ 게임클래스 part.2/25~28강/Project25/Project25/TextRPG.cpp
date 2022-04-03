#include "stdafx.h"
#include "cPlayer.h"
#include "cMonster.h"

void Town(cPlayer* player, bool& playing);		// 플레이어가 이동하거나 행동한 정보를 받아오기 위해 클래스의 인자값으로 받는다.
												// 포인터가 아닌 주소값(&)으로 할 경우 호출할 때 포인터(*)나 다른걸 사용할 필요가 없다.
												// 함수의 매개변수가 포인터(*)를 요구하는 경우 변수의 주소값을 직접 넣어주고,
												// 주소값(&)을 요구할 때 변수를 적으면 함수에서 가져갈 때 변수의 주소값을 가져갑니다.
void Store(cPlayer* player);
void Dungeon(cPlayer* player);

int main()
{
	bool isPlaying = true;
	int nSelect = 0;
	cPlayer* pPlayer = new cPlayer();			// 메모리 관리에 유리하기 위해 포인터로 처리한다.
	pPlayer->SetPlace(EP_TOWN);					// 첫 시작 위치를 마을로 설정

	while (isPlaying)
	{
		system("cls");
		cout << "=================================================" << endl;
		cout << "이름   : " << pPlayer->GetName().c_str() << endl;
		cout << "레벨   : " << pPlayer->GetLevel()<< endl;
		cout << "경험치 : " << pPlayer->GetExp() << endl;
		cout << "체력   : " << pPlayer->GetCurrHp() << " / " << pPlayer->GetMaxHP() << endl;
		cout << "공격력 : " << pPlayer->GetAttDamage() << endl;
		cout << endl;

		cout << "현재 위치 : ";
		switch (pPlayer->GetPlace())
		{
		case EP_QUIT:
		{
			cout << endl;
			cout << "게임을 종료합니다." << endl;
			isPlaying = false;
		}
			break;
		case EP_TOWN:
		{
			cout << "마을" << endl;
			Town(pPlayer, isPlaying);
		}
			break;
		case EP_STORE:
		{
			cout << "상점" << endl;
			Store(pPlayer);
		}
			break;
		case EP_DUNGEON:
		{
			cout << "던전" << endl;
			Dungeon(pPlayer);
		}
			break;
		}
		cout << endl;
	}

	system("pause");

	return 0;
}

void Town(cPlayer* player, bool& playing)
{
	int nSelect;

	cout << "=================================================" << endl;
	cout << "0.종료 1.여관 2.상점 3.던전 : ";
	cin >> nSelect;

	if (nSelect == 0)
	{
		player->SetPlace(EP_QUIT);			// 플레이어 위치를 종료 값으로 입력해준다.
	}
	else if (nSelect == 1)
	{
		cout << "휴식을 취합니다. (HP 최대 회복)" << endl;
		player->SetMaxHp();
		Sleep(1000);

		cout << "마을로 돌아갑니다." << endl;
		player->SetPlace(EP_TOWN);
	}
	else if (nSelect == 2)
	{
		cout << "상점으로 이동합니다." << endl;
		player->SetPlace(EP_STORE);
	}
	else if (nSelect == 3)
	{
		cout << "던전으로 이동합니다." << endl;
		player->SetPlace(EP_DUNGEON);
	}
	else
	{
		cout << "잘못 입력했습니다." << endl;
	}
	Sleep(1000);
}

void Store(cPlayer* player)
{
	cout << "상점에 주인이 업습니다... 마을로 돌아갑니다..." << endl;
	player->SetPlace(EP_TOWN);
	Sleep(1000);
}

void Dungeon(cPlayer* player)
{
	cout << endl << "던전에 입장했습니다" << endl;
	cout << "몬스터와 전투를 시작합니다!!" << endl << endl;

	cMonster* pMonster = new cMonster("오우거", 90, 20, 180);
	while (true)
	{
		system("cls");
		int nPDamage = player->GetAttDamage() + player->GetExDamage();
		int nMDamage = pMonster->GetAttDamage() + pMonster->GetExDamage();

		cout << "=================================================" << endl;
		cout << "이름   : " << player->GetName().c_str() << endl;
		cout << "레벨   : " << player->GetLevel() << endl;
		cout << "경험치 : " << player->GetExp() << endl;
		cout << "체력   : " << player->GetCurrHp() << " / " << player->GetMaxHP() << endl;
		cout << "공격력 : " << player->GetAttDamage() << endl;
		cout << "=================================================" << endl;

		cout << "몬스터 이름   : " << pMonster->GetName() << endl;
		cout << "몬스터 체력   : " << pMonster->GetHp() << endl;
		cout << "몬스터 공격력 : " << pMonster->GetAttDamage()/* + *pMonster->GetExDamage()*/ << " + ?" << endl;
		cout << "=================================================" << endl;
		cout << "토";
		Sleep(300);
		cout << "벌";
		Sleep(300);
		cout << "중";
		Sleep(300);
		cout << ".";
		Sleep(300);
		cout << ".";
		Sleep(300);
		cout << ".";
		Sleep(300);
		cout << endl;

		cout << "몬스터를 공격합니다.";
		cout << "데미지 : " << nPDamage << endl;
		pMonster->TakeDamage(nPDamage);

		if (pMonster->GetHp() <= 0)
		{
			cout << "몬스터를 퇴치했다." << endl;
			cout << "획득 경험치 : " << pMonster->GetExp() << endl;
			player->IncreaseExp(pMonster->GetExp());
			break;

		}

		cout << "몬스터가 공격합니다.";
		cout << "데미지 : " << nMDamage << endl;
		player->TakeDamage(nMDamage);
		system("pause");

		if (player->GetCurrHp() <= 0)
		{
			cout << "캐릭터가 체력이 없습니다. 마을로 도망갑니다." << endl;
			break;
		}
	}
	delete pMonster;
	
	cout << "마을로 돌아갑니다." << endl;
	player->SetPlace(EP_TOWN);
	system("pause");
}