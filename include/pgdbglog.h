#include <stdio.h>
#include <stdlib.h>

#define pgdebug(...)                                \
if (glob_bTraceEnabled == 1){                       \
PgDbgLogger(0, __LINE__, __FILE__, __VA_ARGS__);    \
}
#define pgerror(...)                                \
PgDbgLogger(1, __LINE__, __FILE__, __VA_ARGS__);

#ifndef __PGDBGLOGGER_H__
#define __PGDBGLOGGER_H__

void PgDbgLogger(unsigned long ulErrorType, int iLine, const char *szFile, const char *pszFormat, ...);

#endif //__PGDBGLOGGER_H_