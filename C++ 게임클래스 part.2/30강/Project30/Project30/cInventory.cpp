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

tagItem* cInventory::Delete(string name)    // ������ ����
{
    tagItem* item = NULL;           // �̸����� ã�µ� �������� ���� ���� ������ NULL ���� ��ȯ�ϱ� ���� pointer�� ����Ѵ�.

    vector<tagItem>::iterator vecIter;      // iterator�� �Ἥ ������ �� �����ϴ� ����� ����ϴ� ����
                                            // �˻��� ���ؼ� ������ �ϱ� �����̴�
                                            // index ��ȣ�� ����ؼ� ������ ���, ����� ������ �� �����ϴ�.
                                            // begin + index��ȣ �� ����� ���� �ֱ� �ϴ�.
                                            // index ��ȣ���� �����غ��� ���� ������ ����ϴ� ���� �Ȱ���.

    for (vecIter = m_vecItem.begin(); vecIter != m_vecItem.end(); vecIter++)
    {
        if ((*vecIter).strName == name)     // (*vecIter).strName �Ӹ� �ƴ϶� vecIter->strName ������ε� ������ �����ϴ�. ������ ��� (*veciter)�� �ٷ� ������ �����ϴ�.
        {
            item = new tagItem(vecIter->itemType, vecIter->strName);
            m_vecItem.erase(vecIter);       // ���Ͱ��� �����.
            break;
        }
    }
    // ���Ϳ� ����ü�� ������������ ��Ƶθ� �� ȿ�����̴�.

    return item;
}

void cInventory::Show()
{
    for (int i = 0; i < m_vecItem.size(); i++)
    {
        cout << "������ ���� : ";
        
        switch (m_vecItem[i].itemType)
        {
        case E_ARMOR:
        {
            cout << "��" << endl;
        }
            break;
        case E_WEAPON:
        {
            cout << "����" << endl;
        }
            break;
        case E_HP_POTION:
        {
            cout << "HP ����" << endl;
        }
            break;
        case E_MP_POTION:
        {
            cout << "MP ����" << endl;
        }
            break;
        }
        cout << "������ �̸� : " << m_vecItem[i].strName.c_str() << endl;
        cout << "======================================" << endl;
    }
}

void cInventory::Money()
{
    int nMoney = 1000;
}
