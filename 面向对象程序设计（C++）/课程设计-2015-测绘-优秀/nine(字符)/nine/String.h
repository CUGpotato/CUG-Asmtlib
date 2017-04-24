#include<iostream>
#include<string>

const int n = 40;
using namespace std;

class String
{
	char* str = new char[n];
	char* str0 = new char[n];
	int size = 0;
public:
	String()
	{ 
		for (int i = 0; i < n; i++)str[i] = ' '; 
	}
	String(String &s)
	{
		for (int i = 0; i < size; i++)
		{ 
			s.str[i] = str[i]; s.str0[i] = str0[i]; 
		}
	}
//	~String(){ delete[] str; delete[] str0; }   //引起this指针出错  故注释掉
	void GetString();
	void GetLength();
	void IsEmpty();
	void GetAt();
	void Insert();
	void Delete();
	void Replace();
	friend String operator+(const String& s1, const String& s2);
	String& operator=(const String& s1);
};

