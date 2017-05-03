#include "Logger.h"
#include <stdio.h>
#include <stdarg.h>


/**
**********************************************************************
* 函 数 名:   Logger
* 用    途:   构造函数，在主程序目录下可嵌套目录（前提需建好目录）
* 创建日期:   2016/05/15
* 访 问 性:   public 
* 返 回 值:   
* 参    数:   const TCHAR * FileName
**********************************************************************
*/
Logger::Logger(const TCHAR *FileName)
{

	GetModuleFileName(NULL, m_fileName, MAX_PATH);
	(_tcsrchr(m_fileName, L'\\'))[1] = 0;
	_tcscat(m_fileName, FileName);
	_tsetlocale(0, _T("chs"));
}

/**
**********************************************************************
* 函 数 名:   Write
* 用    途:   写日志，支持%d、%f、%s格式化字符串，类似fprintf函数
* 创建日期:   2016/05/15
* 访 问 性:   public 
* 返 回 值:   int
* 参    数:   const TCHAR * Format
* 参    数:   ...
**********************************************************************
*/
int Logger::Write(const TCHAR * Format, ...)
{
	FILE *pfile = NULL;
	pfile = _tfopen(m_fileName, _T("a+"));
	if (pfile == NULL)
		return -1;
	SYSTEMTIME time;
	GetLocalTime(&time);
	_ftprintf(pfile, L"[%04d/%02d/%02d %02d:%02d:%02d:%03d]", 
		time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);

	va_list ap;
	TCHAR *p;
	TCHAR *sval;
	int ival;
	double dval;
	va_start(ap, Format);
	_vftprintf(pfile, Format, ap);
	//for (p = const_cast<TCHAR *>(Format); *p; p++)
	//{
	//	if (*p != _T('%'))
	//	{
	//		_fputtc(*p, pfile);
	//		continue;
	//	}
	//	switch (*++p)
	//	{
	//	case _T('d'):
	//		ival = va_arg(ap, int);
	//		_ftprintf(pfile, _T("%d"), ival);
	//		break;
	//	case _T('f'):
	//		dval = va_arg(ap, double);
	//		_ftprintf(pfile, _T("%f"), dval);
	//		break;
	//	case _T('s'):
	//		for (sval = va_arg(ap, TCHAR *); *sval; sval++)
	//			_fputtc(*sval, pfile);
	//		break;
	//	default:
	//		_fputtc(*p, pfile);
	//		break;
	//	}
	//}
	va_end(ap);

	_fputtc(_T('\n'), pfile);
	fclose(pfile);
	return 0;
}
