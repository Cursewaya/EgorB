#include "kursach.h"
int main()
{
	/*
 	пока готовы только + и - для целых неотрицательных
	Защиты от "дурака"пока тоже нет
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
		cout << "выберете действие(+,-): ";
		cin >> z;
		cout << "Введите второе число:";
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
		/*a.print();
		cout << z << endl;
		b.print();
		cout << "____________________________________"<<endl;*/
		cout<<"Результат:"
		c.print();
		cout << "Продолжить? (Y or N):";
		cin >> ch;
	}
	return 0;
}
