#include "Point.h"
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

void Point::GetPoint()
{
	cout << "�����������:" << endl;
	int xx, yy;
	cin >> xx >> yy;
	x = xx;
	y = yy;
}

void Point::DisplayPoint()
{
	cout << "������Ϊ��" << x << "," << y << endl;
}


/***********************************class Line*************************************/

Line::Line()
{
	A = 0;
	B = 0;
	C = 0;
	x1 = x2 = y1 = y2 = 0;
	d = 0;
}

void Line::GetLine(Point p1, Point p2)                //�����������߶�
{
	if (p1.x > p2.x)
	{
		Point p3;
		p3 = p1;
		p1 = p2;
		p2 = p3;
	}
	x1 = p1.x;
	x2 = p2.x;
	y1 = p1.y;
	y2 = p2.y;
	if (x1 == x2)  //����x=3���ֱ�߷���
	{
		B = 0;
		A = 1;
		C = -x1;
	}
	else
	{
		A = double(y2 - y1) / double(x2 - x1);
		B = -1;
		C = -A*double(x1)-B*double(y1) ;
		
	}
}

void Line::DisplayLine()        //��ʾ�߶εĽ���ʽ
{
	cout << "�ߵĽ���ʽ��" << setprecision(4)<< A << "x+" << B<<"y+"<<setprecision(4) << C<< "=0" <<"("<<x1<<"��x��"<<x2<<")"<< endl;
}



double Line::GetDistance(Point P)     //����㵽�߶εľ���
{
	double r;
	double ap, bp, cp;
	if (B == 0)
	{
		cp = x1 - P.x;
		d = cp;
		cout << "�㵽�߶εľ����ǣ�" << cp << endl;
		return cp;
	}
	else
	{
		r = ((P.x - x1)*(x2 - x1)+(P.y - y1)*(y2 - y1)) / ((x2-x1)*(x2-x1));
		cout << "ͶӰ����r=" << r << endl;

		ap = sqrt((P.y - y1)*(P.y - y1) + ((P.x - x1)*(P.x - x1)));
		bp = sqrt((P.y - y2)*(P.y - y2) + ((P.x - x2)*(P.x - x2)));
		cp = abs((A*double(P.x) + B*double(P.y) + C) / sqrt(A*A + B*B));

		cout << "�㵽�߶εľ����ǣ�";
		if (r < 0)
		{
			d = ap;
			cout << ap << endl;
			return ap;
		}
		else if (r > 1)
		{
			d = bp;
			cout << bp << endl;
			return bp;
		}
		else
		{
			d = cp;
			cout << cp << endl;
			return cp;
		}
	}
}