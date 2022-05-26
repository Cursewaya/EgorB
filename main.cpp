#include "Big.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string ch="Y";
	while (ch != "N")
	{
		Big a, b,c;
		char z;
		cout << "Введите первое число:";
		cin >> a;
		cout << "Введите действие(+,-,%,/): ";
		cin >> z;
		cout << "Введите второе число:";
		cin >> b;
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
			case int('*') :
				c = a * b;
				break;
			default:
				break;
		}
		cout <<c<<endl;
		cout << "Продолжить? (Y or N):";
		cin >> ch;
	}
	/*Big a, b;
	
		cin >> a >> b;
		cout << "+"<<a + b << endl;
		cout << a - b << endl;
		cout << b - a << endl;
		cout << a * b << endl;
		cout << "a/b:" << a / b << endl;
		cout << "b/a:" << b / a << endl;
		cout << "a%b:" << a % b << endl;
		cout<< "b%a:" << b % a;
	
	cout << endl << a << " " << b;*/
	/*Big o("123456789");
	long long k = 111111111;
	Big d(k);
	Big c("12345678");
	cout <<d<<endl<<o<<endl<< (o /d)<<endl<<o%d<<endl<<(o-c)%d;*/
	return 0;
}
