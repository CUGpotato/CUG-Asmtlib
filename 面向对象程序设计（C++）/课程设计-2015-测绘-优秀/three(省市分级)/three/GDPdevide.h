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
	GDPdevide();          //将文件读入结构体数组
	void Display();        //数据显示
	void SequenceA();      //降序排序
	void SequenceB();       //升序排序
	void devide();
};