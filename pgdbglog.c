#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

#define __FILE__
#define __LINE__


const char *make_temp_name();

void PgDbgLogger(unsigned long ulErrorType, int iLine, const char *szFile, const char *pszFormat, ...){

    static int iCounter = 0;
    FILE * fLogFile;
    iCounter ++;
    int iMaxlen = 256 - 1;
    va_list vaArgumentPointer;
    char szOutputString[256] = {0};
    char *pszType= (ulErrorType==1)?"Error:":"Debug:";

    //================Set local time in file name =================
    time_t tTimeAndDate;
    struct tm * timeinfo;
    time ( &tTimeAndDate );
    timeinfo = localtime ( &tTimeAndDate );
    //=============================================================

    char szFileName[256] = {0};

    if (fLogFile == NULL){

        tTimeAndDate = time(NULL);
        snprintf(szFileName, iMaxlen,"debug_%s.txt",asctime (timeinfo));

        fLogFile = fopen(szFileName, "w");


        va_start(vaArgumentPointer, pszFormat);
        vsnprintf(szOutputString, iMaxlen, pszFormat, vaArgumentPointer);
        va_end(vaArgumentPointer);

        fprintf(fLogFile, "%04i: %s %s, line: %i from %s\n", iCounter, pszType, szOutputString, iLine, szFile);
    }

    /*
    if( fLogFile != NULL) {
        va_start(vaArgumentPointer, pszFormat);
        vsnprintf(szOutputString, iMaxlen, pszFormat, vaArgumentPointer);
        va_end(vaArgumentPointer);
    */


    return;
}
