#include<iostream>
#include<cmath>
#include"string.h"

using namespace std;

#define R long(6371)
#define PI double(3.1415)
#define K double(2*PI*R/360)


class Position 
{
public:
	double m;       //����
	double n;       //γ��

	Position(){};
	Position(double a,double b)
	{
		m = a;
		n = b;
		
	}
	void transform()      //��С��ת��Ϊ�ȷ���
	{
		int x, y, z;
		int a, b, c;
		x = (int)m;
		y = (int)((m - x) * 60);
		z = (int)(((m - x) * 60 - y) * 60);
		cout << "����" << x << "��" << y << "��" << z << "��" << endl;
		a = (int)n;
		b = (int)((n - a) * 60);
		c = (int)(((n - a) * 60 - b) * 60);
		cout << "γ��" << a << "��" << b << "��" << c << "��" << endl;
	};
};



class Earth :public Position             //�����������
{
public:
	Earth(){ cout << endl; }
	void distance(Position& p1, Position p2)
	{

		double d = R*acos(cos(p1.n /180* PI)*cos(p2.n /180* PI)*cos(p1.m / 180*PI - p2.m / 180*PI) + sin(p1.n /180* PI)*sin(p2.n / 180*PI));

		cout << "�������Ϊ" << d <<"ǧ��"<<endl;
	}
};



int main()
{
	cout << "����������ݣ�(����) 116  40��(�人)��114  30" << endl;
	double a,b,c,d;
	cout << "������a�������꣺";
	cin >> a;
	cin >> b;
	cout << "������b�������꣺";
	cin >> c;
	cin >> d;
	
	
		Position P1(a, b), P2(c, d);
		cout << "a���о�γ��Ϊ��\n";
		P1.transform();
		cout << "b���о�γ��Ϊ��\n";
		P2.transform();
		Earth E1; 
		E1.distance(P1, P2);    //�����������
	
	
	system("pause");
}