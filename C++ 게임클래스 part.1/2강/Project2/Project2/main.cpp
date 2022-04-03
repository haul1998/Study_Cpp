#include <iostream>
using namespace std;

// cout : ��� ��ɾ�
// cin : �Է� ��ɾ�
// endl : �ٹٲ� ��ɾ�

/*

10����
0 ~ 9�� ���� ǥ���Ǵ� ������ : ��) 9, 26

2����
0�� 1 �ΰ��� ���ڷ� ǥ���Ǵ� ������ : ��) 0, 1

10���� : 2����
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101

1bit -> 0
1byte == 8bit : 00000000 ~ 111111111 = 2^8 = 0 ~ 255
*/

/*
������ �ڷ���
bool	: 1byte ������ - ���� ������ ǥ���Ѵ�. true(1), false(0)
char	: 1byte ������ - ���� �ϳ��� ǥ�� ��) a, b, c
  - ���� ���ڴ� 1byte���� �ѱ� ���ڴ� 2byte�� �ѱ��� �Ұ���
short	: 2byte ������ (����, 0, ���)
		- ������ �뷮�� �˳��ؼ� �� ������ ���� / short�� int�� ���� ǥ���� �� �ִ� ������ ���� ����
int		: 4byte ������
float	: 4byte �Ǽ��� (�Ҽ����� �����ϴ� ����)
double	: 8byte �Ǽ���
*/

/*
������
���� ������ : =
�� ������ : == (���п����� =)
ex ) a = 10 �� a�� 10�� �ִ´�

��� ������ : + - * /
*/

void main()
{
	// �밡���� ǥ��� : ������ �տ� ������ Ÿ���� ǥ�����ִ� ���, �������� ��� �����ڴ� ���, ���� �̸��� ���� �� �뵵�� ���� ���¹�
	// ex) isPlaying, bPlay
	
	// ���� ����
	bool isPlaying;
	bool bPlay;
	char chLetter;
	short shArmor;
	int nAttack; // int�� �ַ� n���� �����ϴ°� ����, i�� �ݺ����� �ַ� ���̱⿡ Ŭ���̾�Ʈ������ n�� �ַ� ���� / �����ʿ����� i�� ������
	float fSpeed;
	double dPower;

	isPlaying = true;
	bPlay = false;

	chLetter = 'a'; // char�� ��� ���� ����ǥ�� �ؾ���
	shArmor = 10;
	nAttack = 20;
	fSpeed = 3.0f; // �ڿ� f�� ������ float, ���� ������ double
	dPower = 4.0;

	cout << "chLetter : " << chLetter << endl;
	cout << "nAttack : " << nAttack << endl;
	cout << "fSpeed : " << fSpeed << endl;
	cout << shArmor * nAttack << endl; // short�� int�� ��� ������ ����� �����ϴ�

	cout << "�Ŀ��� �Է��ϼ��� : ";
	cin >> dPower;

	cout << "�Է��Ͻ� �Ŀ��� " << dPower << "�Դϴ�." << endl;

	system("pause");	
}