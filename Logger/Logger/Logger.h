#pragma once
#include <tchar.h>
#include <windows.h>

class Logger
{
public:
	Logger(const TCHAR *FileName);
	int Write(const TCHAR * Format, ...);
private:
	TCHAR m_fileName[MAX_PATH];
	Logger(const Logger&);
	Logger & operator=(Logger &);
};
