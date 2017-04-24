#include<iostream>
using namespace std;

class Complex
{//�����࣬������ʵ�����鲿
	double real, imag;
	public:Complex(double r, double i)
	{
	real = r;
	imag = i;
	}
	   
	   Complex operator+(Complex c);
	   Complex operator-(Complex c);
	   Complex operator*(Complex c);
	   Complex& operator=(const Complex &c);
	   friend ostream & operator<<(ostream &out, const Complex &c);
};

Complex Complex::operator+(Complex c)
{
	return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator-(Complex c)
{
	return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator*(Complex c)
{
	return Complex(real *c.real - imag*c.imag, imag*c.real + real*c.imag);
}

ostream & operator<<(ostream &out, const Complex &c)
{//����<<,����Ϊ�ิ�������Ԫ���� 
	return out << c.real << "+" << c.imag << "i" << endl;
}

Complex& Complex::operator=(const Complex &c){//��ֵ����������"="
	real = c.real;
	imag = c.imag;
	return *this;
}

int main()
{
	int a, b, c, d;
	cout << "����c1:";
	cin >> a >> b;
	cout << "����c2:";
	cin>> c >> d;
	Complex c1(a, b);
	Complex c2(c, d);
	cout << "c1=" << c1 << endl;
	cout << "c2=" << c2 << endl;
	cout << "c2-c1=" << c2 - c1 << endl;
	cout << "c2+c1=" << c2 + c1 << endl;
	cout << "c2*c1=" << c2 * c1 << endl;
	c1 = c2;
	cout << "new c1=" << c1 << endl;
	system("pause");
	return 0;
}