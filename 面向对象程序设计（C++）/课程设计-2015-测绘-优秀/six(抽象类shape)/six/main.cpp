#include<iostream>
#include<string>
#include<cmath>
using namespace std;

const double Pi = 3.14159;

class Point
{//坐标点类
public:
	double x, y;
	Point(double xx, double yy) :x(xx), y(yy){}
	Point(){}
};

class Shape{ //基类
public:
	virtual string ShapeName() = 0;
	virtual Point* Position() = 0;
	virtual double GetPerimeter() = 0;
	virtual double GetArea() = 0;
	virtual void ShowPerimeter() = 0;
	virtual void ShowArrea() = 0;
	virtual void ShowPosition();
	Point *position;
	int n;
};

void Shape::ShowPosition()
{//显示位置函数
	this->Position();
	for (int i = 0; i < n; i++)
		cout << "Point " << i << ":" << "(" << position[i].x << "," << position[i].y << ")" << endl;
}

/***********************************Rectangle*****************************/
class Rectangle :public Shape{
public:
	Rectangle(Point _lt, Point _rd) :lt(_lt), rd(_rd){
		length = rd.x - lt.x;
		width = lt.y - rd.y;
		position = new Point[4];
		n = 4;
	}
	string ShapeName(){ return "Rectangle"; }
	Point* Position();
	double GetPerimeter();
	double GetArea();
	void ShowPerimeter(){ cout << "The perimeter of rectangle is:" << GetPerimeter() << endl; }
	void ShowArrea(){ cout << "The area of rectangle is:" << GetArea() << endl; }
	//void ShowPosition();
private:
	Point lt, rd;
	double width, length;
};
Point* Rectangle::Position(){
	position[0] = lt;
	position[3] = rd;
	position[1] = Point(lt.x, rd.y);
	position[2] = Point(rd.x, lt.y);
	return position;
}
double Rectangle::GetPerimeter(){
	return 2 * (width+length);
}
double Rectangle::GetArea(){
	return width*length;
}

/*********************Circle*********************/
class Circle :public Shape{
public:
	Circle(Point o, double r) :O(o), radius(r){
		position = new Point[1];
		n = 1;
	}
	string ShapeName(){ return "Circle"; }
	Point* Position();
	double GetPerimeter();
	double GetArea();
	void ShowPerimeter(){ cout << "The perimeter of circle is:" << GetPerimeter() << endl; }
	void ShowArrea(){ cout << "The area of circle is:" << GetArea() << endl; }
	//void ShowPosition();
private:
	Point O;
	double radius;
};
double Circle::GetPerimeter(){
	return 2 * Pi*radius;
}
double Circle::GetArea(){
	return Pi*radius*radius;
}
Point* Circle::Position(){
	position[0] = O;
	return position;

}
int main()
{
	Rectangle R(Point(0, 4), Point(4, 0));
	Circle C(Point(0, 0), 4);
	cout << R.ShapeName() << ":" << endl;
	R.ShowPerimeter();
	R.ShowArrea();
	R.ShowPosition();
	cout << C.ShapeName() << ":" << endl;
	C.ShowPerimeter();
	C.ShowArrea();
	C.ShowPosition();
	system("pause");
	return 0;
}

