#include<iostream>
#include"Point.h"
#include<iomanip>
#include<cmath>

using namespace std;

int n = 10;

int main()
{
	cout << "测试数据：定点：0 0" << endl << "折线数：3" << endl << "坐标点依次为：" << endl << "0 1" << endl << "1 0" << endl << "4 4" << endl << "4 0" << endl << endl << endl;
	Point P0;
	P0.GetPoint();
	P0.DisplayPoint();
	cout << "输入折线的段数：";
	cin >> n;
	Line L[10];                          //线段类数组构成折线
	Point P[11];                          //折线端点集
	cout << "依次输入折线类点的坐标：" << endl;
	for (int i = 0; i < n + 1; i++)
	{
		P[i].GetPoint();
	}
	for (int i = 0; i < n; i++)
	{
		L[i].GetLine(P[i], P[i + 1]);
	}
	for (int i = 0; i < n; i++)
	{
		L[i].DisplayLine();
		L[i].GetDistance(P0);
	}
	cout << "所以点到折线的距离为：";

	double distance=0;
	if (n > 1)
	{
		distance = L[0].d;
		for (int i = 0; i < n ; i++)
		{
			if (L[i].d < distance)
			{
				distance = L[i].d;
			}
			
		}
	}
	else
	{
		distance = L[0].d;
	}
	cout << distance << endl;
	system("pause");
}