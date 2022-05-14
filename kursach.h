#ifndef KURSACH
#define KURSACH
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>
using namespace std;
class Big
{
private:
	vector<int>bef;
public:
	Big()
	{
		//cout << "open " << this << endl;
	}
	Big(vector<int>&b)
	{
		for (int i = 0; i <b.size(); ++i)
		{
			bef.push_back( b[i]);
		}
		//cout << "open " << this << endl;
	}
	~Big()
	{
		//cout << "close " << this << endl;
	}

	friend Big operator +(Big a, Big b);

	friend Big operator /(Big a, Big b);
	friend Big operator -(Big a, Big b);
	friend Big operator *(Big a, Big b);
	friend bool operator >(Big a, Big b);
	void operator =(Big b);
	void print();
	void scan();

};
#endif
