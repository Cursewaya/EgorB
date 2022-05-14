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
		cout << "Ââåäèòå ïåðâîå ÷èñëî:";
		a.scan();
		cout << "Ââåäèòå äåéñòâèå(+,-,*,/,%): ";
		cin >> z;
		cout << "Ââåäèòå âòîðîå ÷èñëî:";
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
		cout << "Ïðîäîëæèòü? (Y or N):";
		cin >> ch;
	}
	return 0;
}
