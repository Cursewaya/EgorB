#include "kursach.h"
void Big::cut()
{
	while (bef.size() > 1 && bef[0] == 0)
		bef.erase(bef.begin(), bef.begin() + 1);
}
Big operator+(Big a, Big b)
{
	a.cut();
	b.cut();
	if (a.bef.size()>0 && a.bef[0] < 0)
	{
		a.bef[0] *= -1;
		return b - a;
	}
	if (b.bef.size() > 0 && b.bef[0] < 0)
	{
		b.bef[0] *= -1;
		return a-b;
	}
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
	c.cut();
	return c;
}
Big operator-(Big a, Big b)
{
	Big c;
	int znak = 1;
	if (b.bef.size() > 0 && b.bef[0] < 0)
	{
		b.bef[0] *= -1;
		return a + b;
	}
	if (a.bef.size() > 0 && a.bef[0] < 0)
	{
		a.bef[0] *= -1;
		c = a + b;
		c.bef[0] *= -1;
		return c;
	}

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
	a.cut();
	a.bef[0] *= z;
	return a;
}
Big operator*(Big a, Big b)
{
	int znak = 1;
	if (a.bef[0] < 0)
	{
		znak *= -1;
		a.bef[0] *= -1;
	}
	if (b.bef[0] < 0)
	{
		znak *= -1;
		b.bef[0] *= -1;
	}
	if (b > a)
	{
		Big ch = b;
		b = a;
		a = ch;
	}
	int k = 0;
	Big ans;
	reverse(a.bef.begin(), a.bef.end());
	reverse(b.bef.begin(), b.bef.end());
	for (int i = 0; i < b.bef.size(); ++i)
	{
		Big t;
		k = 0;
		for (int j = 0; j < a.bef.size(); ++j)
		{

			t.bef.push_back((a.bef[j] * b.bef[i] + k) % 10);
			k = (a.bef[j] * b.bef[i] + k) / 10;
		}
		if (k != 0)
			t.bef.push_back(k);
		reverse(t.bef.begin(), t.bef.end());
		for (int j = 0; j < i; ++j)
		{
			t.bef.push_back({ 0 });
		}
		ans = ans + t;
		t.bef.erase(t.bef.begin(), t.bef.end());
	}
	ans.cut();
	ans.bef[0] *= znak;
	return ans;
}
Big operator/(Big a, Big b)
{
	int znak = 1;
	a.cut();
	b.cut();
	if (a.bef[0] < 0)
	{
		znak *= -1;
		a.bef[0] *= -1;
	}
	if (b.bef[0] < 0)
	{
		znak *= -1;
		b.bef[0] *= -1;
	}
	if (b.bef[0] == 0)
	{
		cout << "деление на ноль" << endl;
		return b;
	}
	Big ans{ long long(0) };
	Big c = a;
	Big t;
	if (b > c)
		return { ans };
	for (int i = 0; b > t;)
	{
		if (c.bef.size() == 0)
			return ans;
		t.bef.push_back(c.bef[0]);
		c.bef.erase(c.bef.begin(), c.bef.begin() + 1);
	}
	int x = 0;
	while (c.bef.size()!=0 )
	{
		 x = 0;
		while (t > b * (x+1) || (t-b*(x+1)).bef[0]==0)
			x++;
		t = t - b*x;
		ans.bef.push_back(x);
		while (t.bef.size() > 0 && t.bef[0] == 0)
		{
			t.bef.erase(t.bef.begin(), t.bef.begin() + 1);
		}
		t.bef.push_back(c.bef[0]);
		c.bef.erase(c.bef.begin(), c.bef.begin() + 1);
	}
	x = 0;
	while (t > b * (x + 1) || (t - b * (x + 1)).bef[0] == 0)
		x++;
	t = t - b * x;
	ans.bef.push_back(x);
	while (t.bef.size() > 0 && t.bef[0] == 0)
	{
		t.bef.erase(t.bef.begin(), t.bef.begin() + 1);
	}
	ans.cut();
	ans.bef[0] *= znak;
	return ans;
}
Big operator%(Big a, Big b)
{
	return a - b * (a / b);
}

ostream& operator<<(ostream& os, const Big& k)
{
	for (int i = 0; i < k.bef.size(); ++i)
	{
		cout << k.bef[i];
		if ((k.bef.size() - i - 1) % 3 == 0)
		{
			cout << " ";
		}
	}
	return os;
}
istream& operator>> (istream& is, Big& k)
{
	string s;
	int check = 0;
	cin >> s;
	if (s[0] == '-')
	{
		check = 2;
		k.bef.push_back((int(s[1]) - 48) * -1);
	}
	for (int i = 0 + check; i < s.size(); ++i)
	{
		k.bef.push_back(int(s[i]) - 48);
	}
	return is;
}

void Big::operator=(Big a)
{
	bef.erase(bef.begin(), bef.end());
    bef.resize(a.bef.size());
    for (int i = 0; i < bef.size(); ++i)
    {
        bef[i] = a.bef[i];
    }
}
bool operator >(Big l, Big r)
{
	l.cut();
	r.cut();
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
		if (abs(l.bef[i]) > abs(r.bef[i]))
		{
			return 1;
		}
		if (abs(l.bef[i]) < abs(r.bef[i]))
		{
			return 0;
		}
	}
	return 0;
}

Big operator*(Big a, int k)
{
	int b = k;
	Big c;
	if(b==0)
		c.bef.push_back(0);
	while (b > 0)
	{
		c.bef.push_back(b % 10);
		b = b / 10;
	}
	reverse(c.bef.begin(), c.bef.end());
	return a*c;
}
