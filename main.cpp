#include "kursach.h"
int main()
{
	//���� ������ ������ + � - ��� ����� ���������������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string ch="Y";
	while (ch != "N")
	{
		Big a, b,c;
		char z;
		cout << "������� ������ �����:";
		a.scan();
		cout << "������� ��������(+,-,*,/,%): ";
		cin >> z;
		cout << "������� ������ �����:";
		b.scan();
		switch (int(z))
		{
			case int('+') :
				c = a + b;
				break;
			case int('-') :
				c = a -b;
				break;
			default:
				break;
		}
		a.print();
		cout << z << endl;
		b.print();
		cout << "____________________________________"<<endl;
		c.print();
		cout << "����������? (Y or N):";
		cin >> ch;
	}
	return 0;
}