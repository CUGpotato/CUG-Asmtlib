#pragma once
#include<string>
using namespace std;

class CDate
{
	string date;
	int nYear;
	int nMonth;
	int nDay;
public:
	CDate();
	CDate(CDate& D)
	{
		date = D.date;
		nYear = D.nYear;
		nMonth = D.nMonth;
		nDay = D.nDay;
	}
	
	string Set(string s);


	int ComplexCompare(CDate D1);
};

