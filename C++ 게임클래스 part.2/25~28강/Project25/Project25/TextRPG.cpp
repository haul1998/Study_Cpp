#include "stdafx.h"
#include "cPlayer.h"
#include "cMonster.h"

void Town(cPlayer* player, bool& playing);		// �÷��̾ �̵��ϰų� �ൿ�� ������ �޾ƿ��� ���� Ŭ������ ���ڰ����� �޴´�.
												// �����Ͱ� �ƴ� �ּҰ�(&)���� �� ��� ȣ���� �� ������(*)�� �ٸ��� ����� �ʿ䰡 ����.
												// �Լ��� �Ű������� ������(*)�� �䱸�ϴ� ��� ������ �ּҰ��� ���� �־��ְ�,
												// �ּҰ�(&)�� �䱸�� �� ������ ������ �Լ����� ������ �� ������ �ּҰ��� �������ϴ�.
void Store(cPlayer* player);
void Dungeon(cPlayer* player);

int main()
{
	bool isPlaying = true;
	int nSelect = 0;
	cPlayer* pPlayer = new cPlayer();			// �޸� ������ �����ϱ� ���� �����ͷ� ó���Ѵ�.
	pPlayer->SetPlace(EP_TOWN);					// ù ���� ��ġ�� ������ ����

	while (isPlaying)
	{
		system("cls");
		cout << "=================================================" << endl;
		cout << "�̸�   : " << pPlayer->GetName().c_str() << endl;
		cout << "����   : " << pPlayer->GetLevel()<< endl;
		cout << "����ġ : " << pPlayer->GetExp() << endl;
		cout << "ü��   : " << pPlayer->GetCurrHp() << " / " << pPlayer->GetMaxHP() << endl;
		cout << "���ݷ� : " << pPlayer->GetAttDamage() << endl;
		cout << endl;

		cout << "���� ��ġ : ";
		switch (pPlayer->GetPlace())
		{
		case EP_QUIT:
		{
			cout << endl;
			cout << "������ �����մϴ�." << endl;
			isPlaying = false;
		}
			break;
		case EP_TOWN:
		{
			cout << "����" << endl;
			Town(pPlayer, isPlaying);
		}
			break;
		case EP_STORE:
		{
			cout << "����" << endl;
			Store(pPlayer);
		}
			break;
		case EP_DUNGEON:
		{
			cout << "����" << endl;
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
	cout << "0.���� 1.���� 2.���� 3.���� : ";
	cin >> nSelect;

	if (nSelect == 0)
	{
		player->SetPlace(EP_QUIT);			// �÷��̾� ��ġ�� ���� ������ �Է����ش�.
	}
	else if (nSelect == 1)
	{
		cout << "�޽��� ���մϴ�. (HP �ִ� ȸ��)" << endl;
		player->SetMaxHp();
		Sleep(1000);

		cout << "������ ���ư��ϴ�." << endl;
		player->SetPlace(EP_TOWN);
	}
	else if (nSelect == 2)
	{
		cout << "�������� �̵��մϴ�." << endl;
		player->SetPlace(EP_STORE);
	}
	else if (nSelect == 3)
	{
		cout << "�������� �̵��մϴ�." << endl;
		player->SetPlace(EP_DUNGEON);
	}
	else
	{
		cout << "�߸� �Է��߽��ϴ�." << endl;
	}
	Sleep(1000);
}

void Store(cPlayer* player)
{
	cout << "������ ������ �����ϴ�... ������ ���ư��ϴ�..." << endl;
	player->SetPlace(EP_TOWN);
	Sleep(1000);
}

void Dungeon(cPlayer* player)
{
	cout << endl << "������ �����߽��ϴ�" << endl;
	cout << "���Ϳ� ������ �����մϴ�!!" << endl << endl;

	cMonster* pMonster = new cMonster("�����", 90, 20, 180);
	while (true)
	{
		system("cls");
		int nPDamage = player->GetAttDamage() + player->GetExDamage();
		int nMDamage = pMonster->GetAttDamage() + pMonster->GetExDamage();

		cout << "=================================================" << endl;
		cout << "�̸�   : " << player->GetName().c_str() << endl;
		cout << "����   : " << player->GetLevel() << endl;
		cout << "����ġ : " << player->GetExp() << endl;
		cout << "ü��   : " << player->GetCurrHp() << " / " << player->GetMaxHP() << endl;
		cout << "���ݷ� : " << player->GetAttDamage() << endl;
		cout << "=================================================" << endl;

		cout << "���� �̸�   : " << pMonster->GetName() << endl;
		cout << "���� ü��   : " << pMonster->GetHp() << endl;
		cout << "���� ���ݷ� : " << pMonster->GetAttDamage()/* + *pMonster->GetExDamage()*/ << " + ?" << endl;
		cout << "=================================================" << endl;
		cout << "��";
		Sleep(300);
		cout << "��";
		Sleep(300);
		cout << "��";
		Sleep(300);
		cout << ".";
		Sleep(300);
		cout << ".";
		Sleep(300);
		cout << ".";
		Sleep(300);
		cout << endl;

		cout << "���͸� �����մϴ�.";
		cout << "������ : " << nPDamage << endl;
		pMonster->TakeDamage(nPDamage);

		if (pMonster->GetHp() <= 0)
		{
			cout << "���͸� ��ġ�ߴ�." << endl;
			cout << "ȹ�� ����ġ : " << pMonster->GetExp() << endl;
			player->IncreaseExp(pMonster->GetExp());
			break;

		}

		cout << "���Ͱ� �����մϴ�.";
		cout << "������ : " << nMDamage << endl;
		player->TakeDamage(nMDamage);
		system("pause");

		if (player->GetCurrHp() <= 0)
		{
			cout << "ĳ���Ͱ� ü���� �����ϴ�. ������ �������ϴ�." << endl;
			break;
		}
	}
	delete pMonster;
	
	cout << "������ ���ư��ϴ�." << endl;
	player->SetPlace(EP_TOWN);
	system("pause");
}