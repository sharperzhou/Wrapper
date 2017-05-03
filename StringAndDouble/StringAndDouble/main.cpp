#include "StringAndDouble.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	wchar_t pchar[25];
	wchar_t pchar2[80];
	char a[30];
	string str, str2, str3;
	CString cstr, cstr2, cstr3;
	double result;
	while(1){

	scanf("%s", a);
	str = a;
	cstr = a;
	//StringAndDouble::StrtoD(a, result);
	//StringAndDouble::StrtoD(str, result);
	StringAndDouble::StrtoD(cstr, result);
	//StringAndDouble::DtoWholeStr(result, pchar);
	//StringAndDouble::DtoWholeStr(result, str2);
	StringAndDouble::DtoWholeStr(result, cstr2);
	int i =sizeof(StringAndDouble);
	StringAndDouble::FormatType ft = {StringAndDouble::FixedLength, 7, 3};
	//StringAndDouble::DtoFormatStr(result, pchar2, ft);
	//StringAndDouble::DtoFormatStr(result, str3, ft);
	StringAndDouble::DtoFormatStr(result, cstr3, ft);
	//wprintf(L"%s\n", pchar2);
	cout<<cstr2.GetLength()<<" cstr2 = "<<cstr2<<endl;
	cout<<cstr3.GetLength()<<" cstr3 = "<<cstr3<<endl;
	}
	system("pause");
	return 0;
}