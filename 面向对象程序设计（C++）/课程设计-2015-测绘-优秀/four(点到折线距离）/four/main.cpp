#include<iostream>
#include"Point.h"
#include<iomanip>
#include<cmath>

using namespace std;

int n = 10;

int main()
{
	cout << "�������ݣ����㣺0 0" << endl << "��������3" << endl << "���������Ϊ��" << endl << "0 1" << endl << "1 0" << endl << "4 4" << endl << "4 0" << endl << endl << endl;
	Point P0;
	P0.GetPoint();
	P0.DisplayPoint();
	cout << "�������ߵĶ�����";
	cin >> n;
	Line L[10];                          //�߶������鹹������
	Point P[11];                          //���߶˵㼯
	cout << "�������������������꣺" << endl;
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
	cout << "���Ե㵽���ߵľ���Ϊ��";

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