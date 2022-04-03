#pragma once
#include "stdafx.h"

enum E_ITEM
{
	E_ARMOR, E_WEAPON, E_HP_POTION, E_MP_POTION
};

struct tagItem
{
	E_ITEM itemType;
	string strName;
	
	// ������
	tagItem() { };		// �⺻ �����ڰ� ������ �Ʒ��� �ִ� �����ڸ� ����� �� ����.
						// ����ü ���� �� �⺻ �����ڰ� ������ �����ڸ� ����� �� ����.

	// �����ڸ� ����� ������ ���ڰ��� �޾Ƽ� �����ϱ� �����̴�.
	tagItem(E_ITEM _itemType, string _strName)		// ( ) �ȿ� �ִ� ���� ���ڰ�
	{
		itemType = _itemType;
		strName = _strName;
	}
};

class cInventory
{
private:
	vector<tagItem> m_vecItem;

public:
	cInventory();
	~cInventory();

	void Add(tagItem newItem);		// �κ��丮�� ������ �ֱ�
	tagItem* Delete(string name);	// �κ��丮���� ������ ������
	void Show();					// �κ��丮�� �ִ� ������ ��� �����ֱ�
	void Money();
};

