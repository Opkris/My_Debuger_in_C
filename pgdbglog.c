#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define __FILE__
#define __LINE__

void PgDbgLogger(unsigned long ulErrorType, int iLine, const char *szFile, const char *pszFormat, ...){

    static int iCounter = 0;
    FILE * fLogFile = NULL;
    iCounter ++;
    va_list vaArgumentPointer;
    char szOutputString[256] = {0};
    char *pszType= (ulErrorType==1)?"Error:":"Debug:";

    fLogFile =  fopen("debug.txt", "w");

    if( fLogFile != NULL) {
        va_start(vaArgumentPointer, pszFormat);
        vsnprintf(szOutputString,256 - 1, pszFormat, vaArgumentPointer);
        va_end(vaArgumentPointer);

        fprintf(fLogFile, "%04i: %s %s, line: %i from %s\n", iCounter, pszType, szOutputString, iLine, szFile);
    }


    return;
}