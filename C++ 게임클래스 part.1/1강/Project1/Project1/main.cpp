#include <iostream>			// include : �����ϴ� / iostream �̶�� ���̺귯��(������)�� �߰�(���� �ҷ�����)
using namespace std;		// ��ü������ namespace ������ �����ϴ� ��ɾ�. �� ��ɾ ����صθ� ��ɾ�� �տ� std:: �� �Է����� �ʾƵ� �ȴ�.

void main()					// ���� �Լ�, ()�ȿ� ���߿� �Լ� �߰� ����
{
	// std : standard ���̺귯�� ������ ����ϰڴ� ��� ��ɾ�
	cout << "Hello World!!" << endl << "�ȳ��ϼ���!!" << endl;

	// cout : ��� ��ɾ�
	// << : ��� ����
	// endl : endline �� ���Ӹ�. �ٹٲ��� ���ش�.
	// ; : ����� �������� �˷��ִ� ����. ������ ������ ���� �۵��� ���� �ʴ´�.
	std::cout << "Hello World!" << std::endl;
	std::cout << "�ȳ��ϼ���!" << std::endl;
	
	printf("Good Bye C code!!\n");

	system("pause");
}