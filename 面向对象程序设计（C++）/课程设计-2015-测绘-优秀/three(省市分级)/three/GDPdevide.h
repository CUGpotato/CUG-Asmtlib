#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

const int N = 40;

typedef struct
{
	char city[12];
	double amount;
}GDP;

class GDPdevide
{
	int i = 0;
	GDP gdp[N];
public:
	GDPdevide();          //���ļ�����ṹ������
	void Display();        //������ʾ
	void SequenceA();      //��������
	void SequenceB();       //��������
	void devide();
};