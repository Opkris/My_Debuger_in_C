#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

#define __FILE__
#define __LINE__

void PgDbgLogger(unsigned long ulErrorType, int iLine, const char *szFile, const char *pszFormat, ...){

    static int iCounter = 0;
    iCounter ++;
    FILE *fLogFile = NULL;
    time_t tTimeAndDate;
    int iMaxlen = 256 - 1;
    va_list vaArgumentPointer;

    char szFileName[256] = {0};
    char szOutputString[256] = {0};
    char *pszType= (ulErrorType==1)?"Error:":"Debug:";

    if (fLogFile == NULL){

        tTimeAndDate= time(NULL);
        snprintf(szFileName,iMaxlen,"debug_%li.txt",tTimeAndDate);
        fLogFile = fopen(szFileName, "w");

        va_start(vaArgumentPointer, pszFormat);
        vsnprintf(szOutputString, iMaxlen, pszFormat, vaArgumentPointer);
        va_end(vaArgumentPointer);

        fprintf(fLogFile, "%04i: %s %s, line: %i from %s\n", iCounter, pszType, szOutputString, iLine, szFile);
    }
    return;
}
