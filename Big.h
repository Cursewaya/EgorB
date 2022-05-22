#ifndef KURSACH
#define KURSACH

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>
#include <math.h>

using namespace std;
class Big
{
	vector<int> bef;
public:
	Big(){}
	Big(string s)
	{
		int check = 0;
		if (s[0] == '-')
		{
			check = 2;
			bef.push_back((int(s[1]) - 48) * -1);
		}
		for (int i = 0 + check; i < s.size(); ++i)
		{
			bef.push_back(int(s[i]) - 48);
		}
	}
	Big(long long s)
	{
		bef.push_back(s % 10);
		s = s / 10;
		while (s > 0)
		{
			bef.push_back(s % 10);
			s = s / 10;
		}
	}
	Big(vector<int>&b)
	{
		for (int i = 0; i <b.size(); ++i)
		{
			bef.push_back( b[i]);
		}
	}
	Big(const Big& b)
	{
		bef.erase(bef.begin(), bef.end());
		bef.resize(b.bef.size());
		for (int i = 0; i < bef.size(); ++i)
		{
			bef[i] = b.bef[i];
		}
	}
	~Big() {}
	Big operator +(Big b);
	Big operator /(Big b);
	Big operator %(Big b);
	Big operator -(Big b);
	Big operator *(Big b);

	friend Big operator *(Big a,long long b);
	friend Big cut(Big);
	friend bool operator >(Big a,Big b);
	/*friend void operator =(Big a,Big b);*/
	friend ostream& operator<<(ostream& os, const Big& s);
	friend istream& operator>> (istream& is, Big& s);

};
#endif
