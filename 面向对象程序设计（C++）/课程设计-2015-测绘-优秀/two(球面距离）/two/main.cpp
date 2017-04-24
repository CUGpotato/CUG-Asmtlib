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
	double m;       //经度
	double n;       //纬度

	Position(){};
	Position(double a,double b)
	{
		m = a;
		n = b;
		
	}
	void transform()      //把小数转化为度分秒
	{
		int x, y, z;
		int a, b, c;
		x = (int)m;
		y = (int)((m - x) * 60);
		z = (int)(((m - x) * 60 - y) * 60);
		cout << "经度" << x << "°" << y << "’" << z << "”" << endl;
		a = (int)n;
		b = (int)((n - a) * 60);
		c = (int)(((n - a) * 60 - b) * 60);
		cout << "纬度" << a << "°" << b << "’" << c << "”" << endl;
	};
};



class Earth :public Position             //计算球面距离
{
public:
	Earth(){ cout << endl; }
	void distance(Position& p1, Position p2)
	{

		double d = R*acos(cos(p1.n /180* PI)*cos(p2.n /180* PI)*cos(p1.m / 180*PI - p2.m / 180*PI) + sin(p1.n /180* PI)*sin(p2.n / 180*PI));

		cout << "球面距离为" << d <<"千米"<<endl;
	}
};



int main()
{
	cout << "建议测试数据：(北京) 116  40；(武汉)：114  30" << endl;
	double a,b,c,d;
	cout << "请输入a城市坐标：";
	cin >> a;
	cin >> b;
	cout << "请输入b城市坐标：";
	cin >> c;
	cin >> d;
	
	
		Position P1(a, b), P2(c, d);
		cout << "a城市经纬度为：\n";
		P1.transform();
		cout << "b城市经纬度为：\n";
		P2.transform();
		Earth E1; 
		E1.distance(P1, P2);    //计算球面距离
	
	
	system("pause");
}