// Inventory.cpp : 콘솔 응용 프로그램의 진입점을 정의합니다.

#include "stdafx.h"
#include "cInventory.h"

void InitStore(cInventory* inventory);

int main()
{
    cInventory* pPlayerInventory = new cInventory;
    cInventory* pStore = new cInventory;

    InitStore(pStore);

    // 아이템 거래 전 상점 상태 출력
    /*
    cout << "======================================" << endl;
    cout << "\t\t 상점" << endl;
    cout << "======================================" << endl;
    pStore->Show();
    */
    
    tagItem* buyItem = pStore->Delete("튼튼한 무기");    // 2. 이 Delete 부분에서 new가 발생하기   때문에
    if (buyItem != NULL)
    {
        pPlayerInventory->Add(*buyItem);                // 1. 이 Add에서는 add가 발생하지 않아서 Add와 관계없이
        delete buyItem;                                 // 3. delete를 해줘야한다.
    }

    // 아이템 거래 후 상점 상태 출력
    cout << "======================================" << endl;
    cout << "\t\t 상점" << endl;
    cout << "======================================" << endl;
    pStore->Show();

    cout << "\t\t\b플레이어" << endl;
    cout << "======================================" << endl;
    pPlayerInventory->Show();

    delete pPlayerInventory;
    delete pStore;

    system("pause");
    return 0;
}

void InitStore(cInventory* inventory)
{
    tagItem stItem;
    stItem = tagItem(E_ARMOR, "튼튼한 방어구");
    inventory->Add(stItem);

    stItem = tagItem(E_WEAPON, "튼튼한 무기");
    inventory->Add(stItem);

    stItem = tagItem(E_HP_POTION, "HP 물약");
    inventory->Add(stItem);

    stItem = tagItem(E_MP_POTION, "MP 물약");
    inventory->Add(stItem);
}