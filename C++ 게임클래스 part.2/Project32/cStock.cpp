#include "cStock.h"
#include "stdafx.h"

cStock::cStock()
{

}

cStock::~cStock()
{

}

void cStock::AddItem(tagItem newItem)
{
    m_vecItem[newItem.eType].push_back(newItem);
}

tagItem cStock::PickItem(ITEM_TYPE itemType, int index)
{
    return tagItem();
}

vector<tagItem>& cStock::GetItemList(ITEM_TYPE itemType)
{
    // TODO: ���⿡ return ���� �����մϴ�.
}

void cStock::ShowItem(ITEM_TYPE itemType)
{
}
