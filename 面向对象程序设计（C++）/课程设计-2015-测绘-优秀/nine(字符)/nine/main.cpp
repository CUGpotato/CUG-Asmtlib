#include<iostream>
#include<string>

#include"String.h"
using namespace std;

int main()
{
	cout << "²âÊÔÊý¾Ý£ºabcdabcd" << endl << endl;

	String st;
	cout << "ÇëÊäÈë×Ö·û´®s1:";
	st.GetString();
	st.GetLength();
	st.IsEmpty();
	st.GetAt();   //²éÕÒ×Ö·û
	st.Insert();   //²åÈë×Ö·û
	st.Delete();    //É¾³ý×Ö·û
	st.Replace();   //È¡´ú×Ö·û
	String st1;
	cout << "ÇëÊäÈë×Ö·û´®s2:";
	st1.GetString();
	st + st1;
	st = st1;
	system("pause");
	return 0;
}