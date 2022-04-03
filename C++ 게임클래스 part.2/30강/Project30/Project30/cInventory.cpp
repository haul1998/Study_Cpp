#include "cInventory.h"
#include "stdafx.h"


cInventory::cInventory()
{

}

cInventory::~cInventory()
{

}

void cInventory::Add(tagItem newItem)
{
    m_vecItem.push_back(newItem);
}

tagItem* cInventory::Delete(string name)    // 아이템 삭제
{
    tagItem* item = NULL;           // 이름으로 찾는데 아이템이 없을 수도 있으니 NULL 값을 반환하기 위해 pointer를 사용한다.

    vector<tagItem>::iterator vecIter;      // iterator를 써서 접근할 때 접근하는 방식을 사용하는 이유
                                            // 검색을 통해서 지워야 하기 때문이다
                                            // index 번호를 사용해서 지웠을 경우, 지우는 과정이 더 간편하다.
                                            // begin + index번호 를 사용할 수도 있긴 하다.
                                            // index 번호보다 복잡해보일 수도 있지만 사용하다 보면 똑같다.

    for (vecIter = m_vecItem.begin(); vecIter != m_vecItem.end(); vecIter++)
    {
        if ((*vecIter).strName == name)     // (*vecIter).strName 뿐만 아니라 vecIter->strName 방식으로도 접근이 가능하다. 정수의 경우 (*veciter)로 바로 접근이 가능하다.
        {
            item = new tagItem(vecIter->itemType, vecIter->strName);
            m_vecItem.erase(vecIter);       // 벡터값을 지운다.
            break;
        }
    }
    // 벡터에 구조체를 포인터형으로 담아두면 더 효율적이다.

    return item;
}

void cInventory::Show()
{
    for (int i = 0; i < m_vecItem.size(); i++)
    {
        cout << "아이템 종류 : ";
        
        switch (m_vecItem[i].itemType)
        {
        case E_ARMOR:
        {
            cout << "방어구" << endl;
        }
            break;
        case E_WEAPON:
        {
            cout << "무기" << endl;
        }
            break;
        case E_HP_POTION:
        {
            cout << "HP 포션" << endl;
        }
            break;
        case E_MP_POTION:
        {
            cout << "MP 포션" << endl;
        }
            break;
        }
        cout << "아이템 이름 : " << m_vecItem[i].strName.c_str() << endl;
        cout << "======================================" << endl;
    }
}

void cInventory::Money()
{
    int nMoney = 1000;
}
