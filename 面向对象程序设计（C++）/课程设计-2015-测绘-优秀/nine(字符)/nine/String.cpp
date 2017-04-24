#include"String.h"
#include<iostream>
#include<string>

using namespace std;

void String::GetString()
{
	cin >> str;
	size = strlen(str);
}

void String::GetLength()
{
	size = strlen(str);
	cout << "Length is " << size << "." << endl;
}

void String::IsEmpty()
{
	size = strlen(str);
	if (size == 0)
	{
		cout << "string is empty!" << endl;
	}
	else
	{
		cout << "string is not empty!" << endl;
	}
}

void String::GetAt()
{
	cout << "输入要查找的字母：";
	char a;
	cin >> a;
	int i;
	cout << "字母的位置为：";
	for (i = 0; i < size; i++)
	{
		if (a == str[i])
			cout << i + 1 << "  ";
	}
	cout << endl;
}

void String::Insert()
{
	cout << "插在第几位：";
	int m;
	cin >> m;
	if (m > size + 1)
	{
		cout << "请输入正确数字！";
	}
	else
	{
		cout << "输入s1要插入的字符串：";
		char* str1 = new char[n];
		cin >> str1;
		int size1 = 0;
		size1 = strlen(str1);
		for (int i = 0; i < m - 1; i++)
		{
			str0[i] = str[i];
		}
		for (int i = m - 1; i < m + size1 - 1; i++)
		{
			str0[i] = str1[i - m + 1];
		}
		for (int i = m + size1 - 1; i <size + size1; i++)
		{
			str0[i] = str[i - size1];
		}

		for (int i = 0; i < size + size1; i++)
		{
			cout << str0[i] ;
		}
		cout << endl;

		delete str1;
	}
}

void String::Delete()
{
	cout << "输入s1要删除的子串位置：";
	int a = 0;
	int b = 0;
	if (b > size)
	{
		cout << "请输入正确数字！";
	}
	else
	{
		cin >> a >> b;
		char* str1 = new char[n];
		for (int i = 0; i < a - 1; i++)
		{
			str1[i] = str[i];
		}
		for (int i = a - 1; i < size - b + a; i++)
		{
			str1[i] = str[i + b - a + 1];
		}
		cout << str1 << endl;
		delete str1;
	}
}

void String::Replace()
{
	cout << "输入s1要取代的位置：";
	int a, b;
	cin >> a >> b;
	cout << "输入s1要取代的字符串：";
	char* str1 = new char[n];
	cin >> str1;
	int size1 = strlen(str1);
	if (size1 != b - a + 1)
	{
		cout << "请输入正确长度字符串：";
	}
	else
	{
		for (int i = a - 1; i < b; i++)
		{
			str[i] = str1[i - a + 1];
		}
		cout << str << endl;
		delete str1;
	}
}

String operator+(const String& s1, const String& s2)
{
	String t;
//	delete t.str,t.str0;
	for (int i = 0; i < s1.size; i++)
	{
		t.str[i] = s1.str[i];
	}
	for (int i = s1.size; i < s1.size + s2.size; i++)
	{
		t.str[i] = s2.str[i - s1.size];
	}
	cout << "s1与s2拼接后的字符串为：";
	for (int i = 0; i < s1.size + s2.size; i++)
	{
		cout <<t.str[i] ;
	}
	cout << endl;
	return t;
}

String&String::operator=(const String& s1)
{
    delete []str;
	size = s1.size;
	char *str = new char[size];
	for (int i = 0; i < size; i++)
	{
		str[i] = s1.str[i];
	}
	cout << "将s2赋值给s1,并输出赋值结果：";
	for (int i = 0; i < size; i++)
	{
		cout<<str[i];
	}

	cout << endl;
	return *this;
}