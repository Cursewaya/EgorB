#include "kursach.h"

Big operator+(Big a, Big b)
{
	Big c;
	if (b > a)
	{
		Big t = a;
		a = b;
		b = t;
	}
	reverse(b.bef.begin(), b.bef.end());
	reverse(a.bef.begin(), a.bef.end());
	
	int k = 0, i = 0;
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
	if (b > a)
	{
		Big ch = a;
		a = b;
		b = ch;
		z = -1;
	}
	reverse(b.bef.begin(), b.bef.end());
	reverse(a.bef.begin(), a.bef.end());
	
	for (int i = 0; i < b.bef.size(); ++i)
	{
		if (a.bef[i] - b.bef[i] - k < 0)
		{
			if (i + 1 < a.bef.size())
			{
				a.bef[i] += 10;
				a.bef[i] -= (b.bef[i] + k);
				k = 1;
			}
		}
		else
		{
			a.bef[i] -= (b.bef[i] + k);
			k = 0;
		}
	}
	for (int i = b.bef.size(); k != 0; ++i)
	{
		if (a.bef[i]  - k < 0)
		{
			if (i + 1 < a.bef.size())
			{
				a.bef[i] += 10;
				a.bef[i] -= k;
				k = 1;
			}
		}
		else
		{
			a.bef[i] -= k;
			k = 0;
		}
	}
	reverse(a.bef.begin(), a.bef.end());
	while(a.bef[0] == 0&&a.bef.size()>1)
	{
		a.bef.erase(a.bef.begin() , a.bef.begin() + 1);
	}
	a.bef[0] *= z;
	return a;
}
Big operator%(Big a, Big b)
{
	vector<int>vec(1, 0);
	if (b > a)
	{
		return a;
	}
	reverse(b.bef.begin(), b.bef.end());
	reverse(a.bef.begin(), a.bef.end());
	for (int i = 0; a.bef[i] == 0 && b.bef[i] == 0 && i < a.bef.size() && i < b.bef.size();++i)
	{
		a.bef.erase(a.bef.begin(), a.bef.begin() + 1);
		b.bef.erase(b.bef.begin(), b.bef.begin() + 1);
	}
	reverse(b.bef.begin(), b.bef.end());
	reverse(a.bef.begin(), a.bef.end());
	if (b.bef.size() == 1 && b.bef[0] == 1)
	{
		return { vec };
	}
	if (b.bef.size() == 1 && b.bef[0] == 2)
	{
		vec[0] = b.bef[0] % 2;
		return { vec };
	}
	if (b.bef.size() == 1 && b.bef[0] == 5)
	{
		vec[0] = b.bef[0] % 5;
		return { vec };
	}
	while (!(b > a))
	{
		a = a - b;
	}
	return a;
}
Big operator/(Big a, Big b)
{
	vector<int>vec(1, 0);
	if (b > a)
	{
		return { vec };
	}
	Big c{ vec };
	vec[0] = 1;
	Big k{ vec };
	while (!(b > a))
	{
		a = a - b;
		c = c + k;
	}
	return c;
}

Big operator*(Big a, Big b)
{
	/*if (b > a)
	{
		Big ch = a;
		b = a;
		a = ch;
	}
	int k = 0;
	Big ans;
	reverse(a.bef.begin(), a.bef.end());
	reverse(b.bef.begin(), b.bef.end());
	for (int i = 0; i < b.bef.size(); ++i)
	{
		Big c;
		for (int j = 0; j < a.bef.size(); ++j)
		{
			for (int z = 0; z < i; ++z)
			{
				c.bef.push_back(0);
			}
			c.bef.push_back((a.bef[j] * b.bef[i] + k) % 10);
			k = (a.bef[j] * b.bef[i] + k) / 10;
		}
		reverse(c.bef.begin(), c.bef.end());
		ans = ans + c;
		
	}
    return ans;*/
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
	/*cout << "Введите действие(+,-,*,/,%): ";
	char z;
	cin >> z;
	cout << "Введите второе число: ";*/
}

void Big::operator=(Big a)
{
    bef.resize(a.bef.size());
    for (int i = 0; i < bef.size(); ++i)
    {
        bef[i] = a.bef[i];
    }
}
bool operator >(Big l, Big r)
{
	if (l.bef.size() > r.bef.size())
	{
		return true;
	}
	if (l.bef.size() < r.bef.size())
	{
		return false;
	}
	for (int i = 0; i < l.bef.size(); ++i)
	{
		if (l.bef[i] > r.bef[i])
		{
			return 1;
		}
		if (l.bef[i] < r.bef[i])
		{
			return 0;
		}
	}
	return 0;
}





