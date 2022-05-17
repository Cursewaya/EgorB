#include "kursach.h"
int main()
{
	/*
	Готовы: +,-,/ и %. Последние два буду переделывать через умножение,
	а то (3*10^15)/3 будет считать примерно 31 млн лет
	*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string ch="Y";
	while (ch != "N")
	{
		Big a, b,c;
		char z;
		cout << "Введите первое число:";
		a.scan();
		cout << "Введите действие(+,-,%,/): ";
		cin >> z;
		cout << "Введите второе число:";
		b.scan();
		switch (int(z))
		{
			case int('+') :
				c = a + b;
				break;
			case int('-') :
				c = a - b;
				break;
			case int('%') :
				c = a % b;
				break;
			case int('/') :
				c = a / b;
				break;
			default:
				break;
		}
		c.print();
		cout << "Продолжить? (Y or N):";
		cin >> ch;
	}
	return 0;
}
