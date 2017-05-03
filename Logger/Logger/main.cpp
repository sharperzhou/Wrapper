#include "Logger.h"
#include <tchar.h>
int main()
{
	Logger logger(_T("Logger.log"));
	//logger.Write(L" ‰≥ˆ»’÷æ");
	int a = 1;
	int b = 2;
	double c = (a + b) * 1.0;
	logger.Write(_T("a = %d, b = %d, a + b = 0x%X"), a, b, c);
	TCHAR *str = _T("Hello");
	TCHAR *str2 = _T("World");
	double d1 = 78.192;
	logger.Write(_T("%s %s! d1 = %f"), str, str2, d1);
	return 0;
}