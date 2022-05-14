#include "kursach.h"

Big operator+(Big a, Big b)
{
	Big c;
	reverse(b.bef.begin(), b.bef.end());
	reverse(a.bef.begin(), a.bef.end());
	int k = 0, i = 0;
	if (b > a)
	{
		Big t = a;
		a = b;
		b = t;
	}
	while (i < a.bef.size())
	{
		if (i < b.bef.size())
		{
			c.bef.push_back((a.bef[i] + b.bef[i] + k) % 10);
			k = (a.bef[i] + b.bef[i] + k) / 10;
		}
		else
		{
			c.bef.push_back((a.bef[i] + k) % 10);
			k = (a.bef[i] + k) / 10;
		}
		++i;
	}
	if (k != 0)
		c.bef.push_back(k);
	reverse(c.bef.begin(), c.bef.end());
	return c;
}
Big operator-(Big a, Big b)
{
	Big c;
	int z = 1;
	int k = 0;
	reverse(b.bef.begin(), b.bef.end());
	reverse(a.bef.begin(), a.bef.end());
	if (b > a)
	{
		Big ch = a;
		a = b;
		b = ch;
		z = -1;
	}
	for (int i = 0; i < b.bef.size(); ++i)
	{
		if (a.bef[i] - b.bef[i] < 0)
		{
			if (i + 1 < a.bef.size())
			{
				a.bef[i] += 10;
				a.bef[i + 1]--;
			}
		}
		a.bef[i] -= b.bef[i];
	}
	reverse(a.bef.begin(), a.bef.end());
	a.bef[0] *= -1;
	return a;
}

Big operator*(Big a, Big b)
{
    return Big();
}
Big operator/(Big a, Big b)
{
    return Big();
}

void Big::print()
{
	for (int i = 0; i < bef.size(); ++i)
	{
		cout << bef[i];
	}
	cout << endl;
}
void Big::scan()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		bef.push_back(int(s[i]) - 48);
	}
	/*cout << "Ââåäèòå äåéñòâèå(+,-,*,/,%): ";
	char z;
	cin >> z;
	cout << "Ââåäèòå âòîðîå ÷èñëî: ";*/
}

void Big::operator=(Big a)
{
    bef.resize(a.bef.size());
    for (int i = 0; i < bef.size(); ++i)
    {
        bef[i] = a.bef[i];
    }
}
bool operator >(Big a, Big b)
{
	if (a.bef.size() > b.bef.size())
	{
		return 1;
	}
	else
	{
		reverse(b.bef.begin(), b.bef.end());
		reverse(a.bef.begin(), a.bef.end());
		for (int i = 0; i < a.bef.size(); ++i)
		{
			if (a.bef[i] > b.bef[i])
			{
				return 1;
			}
			if (a.bef[i] < b.bef[i])
				return 0;
		}
		return 0;
	}
}



