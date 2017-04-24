#include"GDPdevide.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

GDPdevide::GDPdevide()                               //将文件读入结构体数组
{
	ifstream myfiles;
	myfiles.open("省市GDP.txt");
	if (!myfiles.is_open())
	{
		cout << "Can't open files!" << endl;
	}
	else
	{
		while (!myfiles.eof())
		{
			myfiles >> gdp[i].city >> gdp[i].amount;
			i++;
		}
	}
	myfiles.close();
	cout << "文件读入测试：" << endl;
	for (int j = 0; j < i-1; j++)
	{
		printf("%s", gdp[j].city);
		cout << "\t";
		cout << setprecision(7) << gdp[j].amount << endl;
	}
	cout << "共有" << i << "个城市" << endl;
}


void GDPdevide::Display()
{
	cout << "文件读入测试：" << endl;
	for (int j = 0; j < i-1; j++)
	{
		printf("%s", gdp[j].city);
		cout << "\t";
		cout << setprecision(7) << gdp[j].amount << endl;
	}
}



void GDPdevide::SequenceA()                    //冒泡法升序排序
{
	GDP GDPtemp;
	int j,k;
	for (j = i-1; j >=0 ;j--)
	{
		for (k =1; k <j;k++)
		{
			if (gdp[k].amount < gdp[k - 1].amount)
			{
				GDPtemp= gdp[k];
				gdp[k] = gdp[k - 1];
				gdp[k - 1] = GDPtemp;
			}
		}
	}
}


void GDPdevide::SequenceB()                    //选择法降序排序
{
	GDP GDPtemp;
	int j, k,t;
	for (j = 0; j <i-1; j++)
	{
		for (k = j+1; k <i-1; k++)
		{
			if (gdp[k].amount > gdp[k - 1].amount)
			{
				t = k;
			}
			 GDPtemp=gdp[j];
			 gdp[j] = gdp[t];
			 gdp[t] = GDPtemp;
		}
	}
}



void GDPdevide::devide()                 //分组
{
	double amount = 0;
	for (int j = 0; j < i-1; j++)
	{
		amount += gdp[j].amount;
	}


	cout << "GDP总值为：" << amount << endl<<endl; 
	amount = amount / 3;
	

	int A = 0;
	double amount1 = 0;

	for (int j = 0; j < i-1; j++)
	{
		if (amount1 < amount)
		{
			amount1 += gdp[j].amount;
			A++;
		}
	}


	cout << "第一等级城市有" << A << "个。" << endl;
	cout << "分别是：" << endl;

	for (int j = 0; j < A; j++)
	{
		cout << gdp[j].city << "\t";
	}

	cout << endl;
	cout << "GDP总值为" << setprecision(8) << amount1 << endl << endl;

	int B = A;
	double amount2 = 0;

	for (int j = A; j < i-1; j++)
	{
		if (amount2 < amount)
		{
			amount2 += gdp[j].amount;
			B++;
		}
	}

	cout << "第二等级城市有" << B - A << "个。" << endl;
	cout << "分别是：" << endl;

	for (int j = A; j < B; j++)
	{
		cout << gdp[j].city << "\t";
	}
	cout << endl;
	cout << setprecision(8) << "GDP总值为" << amount2 << endl << endl;

	double amount3 = 0;

	for (int j = B; j < i-1; j++)
	{
		amount3 += gdp[j].amount;
	}
	cout << "第三等级城市有" << i - B << "个。" << endl;
	cout << "分别是：" << endl;
	for (int j = B; j < i-1; j++)
	{
		cout << gdp[j].city << "\t";
	}
	cout << endl;
	cout << setprecision(8) << "GDP总值为" << amount3 << endl << endl;

	system("pause");

}
