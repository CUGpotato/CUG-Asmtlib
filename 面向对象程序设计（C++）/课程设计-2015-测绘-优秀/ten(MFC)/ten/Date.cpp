#include "stdafx.h"
#include "Date.h"


CDate::CDate()
{
}

string CDate::Set(string s)
{
	date = s;
	string y = "/";
	int iPosition1 = date.find(y, 0);//从0位置开始寻找字符串y，返回的是找到的字母的下标
	//如果没找到，将返回－1
	string str1 = date.substr(0, 4);
	nYear = atoi(str1.c_str());
	int iPosition2 = date.find(y, 5);//从5位置开始寻找字符串y，返回的是找到的字母的下标
	//如果没找到，将返回－1
	string str2 = date.substr(5, iPosition2 - 5);
	nMonth = atoi(str2.c_str());
	string str3 = date.substr(iPosition2 + 1);
	nDay = atoi(str3.c_str());
	return date;
}

int CDate::ComplexCompare(CDate D1)
{
	int i;

	int month_day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year1 = nYear - 1;  // 因为欲求距离1年1月1日的距离
	int days1 = year1 * 365 + nYear / 4 - nYear / 100 + nYear / 400;  //求得之前闰年的数量并在天数上进行想加
	if (nYear % 4 == 0 && nYear % 100 != 0 || nYear % 400 == 0) month_day[1]++; //当前年为闰年，二月加 1
	for (i = 0; i<nMonth - 1; i++)
		days1 += month_day[i];
	days1 += nDay - 1;  

	int month_day1[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year2 = D1.nYear - 1;  // 因为欲求距离1年1月1日的距离
	int days2 = year2 * 365 + D1.nYear / 4 - D1.nYear / 100 + D1.nYear / 400;  //求得之前闰年的数量并在天数上进行想加
	if (nYear % 4 == 0 && nYear % 100 != 0 || nYear % 400 == 0) month_day1[1]++; //当前年为闰年，二月加 1
	for (i = 0; i<D1.nMonth - 1; i++)
		days2 += month_day[i];
	days2 += D1.nDay - 1;

	int days = days1 - days2;//两个距离相减得到相距天数

	return days;
}