#include "Temperature.h"
#include <iostream>
using namespace std;

int main()
{
	Temperature temper(12.5, C);
	cout<<"�¶�Ϊ��"<<temper.GetValue(K)<<endl;
	Temperature temper2;
	temper2.SetValue(25, C);
	double *p = temper2.GetValues();
	cout<<"�����¶�Ϊ��"<<p[1]<<endl;
	double val[4];
	for (int i = 0; i < sizeof(val) / sizeof(double); i++)
	{
		val[i] = temper.GetValues()[i];
		cout<<"�¶�"<<i<<"��ֵΪ��"<<val[i]<<endl;
	}
	system("pause");
	return 0;
}