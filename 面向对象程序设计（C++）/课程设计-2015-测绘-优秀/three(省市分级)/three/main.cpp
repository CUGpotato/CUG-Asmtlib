#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"GDPdevide.h"

using namespace std;

int main()
{
	GDPdevide g;
	g.SequenceA();    //ð���������к���
	g.Display();
	g.SequenceB();    //ѡ�񷨽���
	g.Display();
	g.devide();
}