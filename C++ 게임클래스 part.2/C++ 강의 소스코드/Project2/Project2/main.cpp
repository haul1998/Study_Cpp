#include <iostream>		// C++ ǥ�� ���̺귯��

using namespace std;

// �⺻ ��ɾ�
// cout, cin

/* �ڷ���
1Byte = 8bit

bool : 1����Ʈ ���� - ���� ������ ǥ�� - true, false - 1, 0
char : 1����Ʈ ������ - 'a' 'b'
short : 2����Ʈ ������(����, 0, ���)
int : 4����Ʈ ������
float : 4����Ʈ �Ǽ���(�Ҽ���)
double : 8����Ʈ �Ǽ���
*/

/* ������
���� ������ =
���� A = 10 => A�� 10�� ����.
���α׷��� A = 10 => A�� 10�� �����Ѵ�.

��� ������ + - * /
*/

void main()
{
	//  �밡���� ǥ��� ���� ����
	bool isTest, bTest;
	char chLetter;
	int nData, nData2, nData3;
	float fData;
	double dData;

	//isTest = true;
	isTest = 10;
	bTest = false;
	// bTest = 0;

	chLetter = 'a';

	nData = 10;

	fData = 0.5f;

	dData = 0.5;

	cout << "isTest " << isTest << endl;
	cout << "chLetter " << chLetter << endl;
	cout << "nData " << nData << endl;
	cout << "fData " << fData << endl;
	cout << "dData " << dData << endl;
	cout << "==============================" << endl;

	nData = 10;
	nData2 = 3;
	nData3 = nData + nData2;
	cout << "nData + nData2 = " << nData3 << endl;
	cout << "nData * nData2 = " << nData * nData2 << endl;
	cout << "==============================" << endl;

	cout << "������ �Է� �ϼ��� : ";
	cin >> nData3;
	cout << nData3 << endl;

	system("pause");
}