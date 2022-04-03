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
	
	// 생성자
	tagItem() { };		// 기본 생성자가 없으면 아래에 있는 생성자를 사용할 수 없다.
						// 구조체 선언 시 기본 생성자가 없으면 생성자를 사용할 수 없다.

	// 생성자를 만드는 이유는 인자값을 받아서 생성하기 위함이다.
	tagItem(E_ITEM _itemType, string _strName)		// ( ) 안에 있는 것이 인자값
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

	void Add(tagItem newItem);		// 인벤토리에 아이템 넣기
	tagItem* Delete(string name);	// 인벤토리에서 아이템 꺼내기
	void Show();					// 인벤토리에 있는 아이템 목록 보여주기
	void Money();
};

