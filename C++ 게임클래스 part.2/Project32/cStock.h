#pragma once
#include "stdafx.h"

enum ITEM_TYPE
{
	ITEM_ARMOR = 0,
	ITEM_WEAPON,
	ITEM_RING1,
	ITEM_RING2,
	ITEM_HP_POTION,
	ITEM_MP_POTION,
	ITEM_TYPE_NUM			// 아이템 종류 개수
};

struct tagItem
{
	string		strName;	// 아이템 이름
	ITEM_TYPE	eType;		// 아이템 타입
	string		strDesc;	// 아이템 설명
	int			nAttribute;	// 아이템 속성 (방어력, 공격력, 회복량 등)
	int			nPrice;		// 아이템 가격
};

class cStock
{
protected:					// 상속을 위해 protected 구역에 선언
	vector<tagItem>				m_vecItem[ITEM_TYPE_NUM];
	vector<tagItem>::iterator	m_vecItem;

public:
	cStock();
	~cStock();

	void AddItem(tagItem newItem);						// 아이템 추가
	tagItem PickItem(ITEM_TYPE itemType, int index);	// 아이템 꺼내기 (삭제 및 정보 반환)
	vector<tagItem>& GetItemList(ITEM_TYPE itemType);	// 아이템 목록 반환 (요구 종류)
	void ShowItem(ITEM_TYPE itemType);					// 아이템 목록 화면에 출력
};