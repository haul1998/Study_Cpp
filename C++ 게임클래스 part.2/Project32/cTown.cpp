#include "cTown.h"

cTown::cTown()
{

}

cTown::~cTown()
{

}

void cTown::MainPlay(LOCATION& eCurrLoc)
{
	int nSelect;
	cout << "==================================" << endl;
	cout << "  C++ ������ ���Ű��� ȯ���մϴ�"   << endl;
	cout << "==================================" << endl;
	cout << "1.�κ��丮 2.���� : ";
	cin >> nSelect;
	
	if (nSelect != 1 and nSelect != 2)
	{
		eCurrLoc = LOCATION_TOWN;
	}
	else
	{
		eCurrLoc = (LOCATION)nSelect;
	}

	switch (nSelect)
	{
	case 1:
	{
		eCurrLoc = LOCATION_INVENTORY;
	}
		break;
	case 2:
	{
		eCurrLoc = LOCATION_SHOP;
	}
		break;
	default:
	{
		eCurrLoc = LOCATION_TOWN;
	}
		break;
	}
}
