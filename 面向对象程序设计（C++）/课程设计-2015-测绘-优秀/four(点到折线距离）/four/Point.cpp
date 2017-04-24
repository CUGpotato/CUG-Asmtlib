#include "Point.h"
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

void Point::GetPoint()
{
	cout << "请输入点坐标:" << endl;
	int xx, yy;
	cin >> xx >> yy;
	x = xx;
	y = yy;
}

void Point::DisplayPoint()
{
	cout << "点坐标为：" << x << "," << y << endl;
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

void Line::GetLine(Point p1, Point p2)                //由两点生成线段
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
	if (x1 == x2)  //形如x=3类的直线方程
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

void Line::DisplayLine()        //显示线段的解析式
{
	cout << "线的解析式：" << setprecision(4)<< A << "x+" << B<<"y+"<<setprecision(4) << C<< "=0" <<"("<<x1<<"≤x≤"<<x2<<")"<< endl;
}



double Line::GetDistance(Point P)     //计算点到线段的距离
{
	double r;
	double ap, bp, cp;
	if (B == 0)
	{
		cp = x1 - P.x;
		d = cp;
		cout << "点到线段的距离是：" << cp << endl;
		return cp;
	}
	else
	{
		r = ((P.x - x1)*(x2 - x1)+(P.y - y1)*(y2 - y1)) / ((x2-x1)*(x2-x1));
		cout << "投影参数r=" << r << endl;

		ap = sqrt((P.y - y1)*(P.y - y1) + ((P.x - x1)*(P.x - x1)));
		bp = sqrt((P.y - y2)*(P.y - y2) + ((P.x - x2)*(P.x - x2)));
		cp = abs((A*double(P.x) + B*double(P.y) + C) / sqrt(A*A + B*B));

		cout << "点到线段的距离是：";
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