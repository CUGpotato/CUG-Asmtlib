#include<iostream>
#include<string>

#include"String.h"
using namespace std;

int main()
{
	cout << "�������ݣ�abcdabcd" << endl << endl;

	String st;
	cout << "�������ַ���s1:";
	st.GetString();
	st.GetLength();
	st.IsEmpty();
	st.GetAt();   //�����ַ�
	st.Insert();   //�����ַ�
	st.Delete();    //ɾ���ַ�
	st.Replace();   //ȡ���ַ�
	String st1;
	cout << "�������ַ���s2:";
	st1.GetString();
	st + st1;
	st = st1;
	system("pause");
	return 0;
}