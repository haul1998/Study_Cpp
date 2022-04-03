#pragma once
#include "cStock.h"
class cInventory : public cStock
{
private:
	int m_nMoney;

public:
	cInventory();
	~cInventory();
};

