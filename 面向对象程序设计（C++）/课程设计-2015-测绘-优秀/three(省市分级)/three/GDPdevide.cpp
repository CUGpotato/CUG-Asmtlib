#include"GDPdevide.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

GDPdevide::GDPdevide()                               //���ļ�����ṹ������
{
	ifstream myfiles;
	myfiles.open("ʡ��GDP.txt");
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
	cout << "�ļ�������ԣ�" << endl;
	for (int j = 0; j < i-1; j++)
	{
		printf("%s", gdp[j].city);
		cout << "\t";
		cout << setprecision(7) << gdp[j].amount << endl;
	}
	cout << "����" << i << "������" << endl;
}


void GDPdevide::Display()
{
	cout << "�ļ�������ԣ�" << endl;
	for (int j = 0; j < i-1; j++)
	{
		printf("%s", gdp[j].city);
		cout << "\t";
		cout << setprecision(7) << gdp[j].amount << endl;
	}
}



void GDPdevide::SequenceA()                    //ð�ݷ���������
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


void GDPdevide::SequenceB()                    //ѡ�񷨽�������
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



void GDPdevide::devide()                 //����
{
	double amount = 0;
	for (int j = 0; j < i-1; j++)
	{
		amount += gdp[j].amount;
	}


	cout << "GDP��ֵΪ��" << amount << endl<<endl; 
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


	cout << "��һ�ȼ�������" << A << "����" << endl;
	cout << "�ֱ��ǣ�" << endl;

	for (int j = 0; j < A; j++)
	{
		cout << gdp[j].city << "\t";
	}

	cout << endl;
	cout << "GDP��ֵΪ" << setprecision(8) << amount1 << endl << endl;

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

	cout << "�ڶ��ȼ�������" << B - A << "����" << endl;
	cout << "�ֱ��ǣ�" << endl;

	for (int j = A; j < B; j++)
	{
		cout << gdp[j].city << "\t";
	}
	cout << endl;
	cout << setprecision(8) << "GDP��ֵΪ" << amount2 << endl << endl;

	double amount3 = 0;

	for (int j = B; j < i-1; j++)
	{
		amount3 += gdp[j].amount;
	}
	cout << "�����ȼ�������" << i - B << "����" << endl;
	cout << "�ֱ��ǣ�" << endl;
	for (int j = B; j < i-1; j++)
	{
		cout << gdp[j].city << "\t";
	}
	cout << endl;
	cout << setprecision(8) << "GDP��ֵΪ" << amount3 << endl << endl;

	system("pause");

}
