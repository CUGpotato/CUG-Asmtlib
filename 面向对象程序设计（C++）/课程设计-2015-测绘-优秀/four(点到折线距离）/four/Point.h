#pragma once

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

class Point
{
public:
	int x;
	int y;
//	double d;
	Point(int xx=0, int yy=0)
	{
		x = xx;
		y = yy;
	}
	Point(Point& p)
	{
		x = p.x;
		y = p.y;
	}
	
	int GetX(){ return x; }
	int GetY(){ return y; }
	virtual void GetPoint();
	void DisplayPoint();
	char operator[](int i)const;
//	double Distance(Point p1, Point p2);

	friend class Line;
};


class Line 
{
	double A;
	double B;
	double C;
	int x1, x2, y1, y2;
	
public:

	double d = 0;

	Line();
	Line(Line& L)
	{
		A = L.A;
		B = L.B;
		C = L.C;
		x1 = L.x1;
		x2 = L.x2;
		y1 = L.y1;
		y2 = L.y2;
		d = L.d;
	}
	void GetLine(Point p1, Point p2);
	void DisplayLine();
	double GetDistance(Point P);
	void Judge();

//	friend class Point;
};
