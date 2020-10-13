#include <stdio.h>
#include <stdlib.h>
#include "pgdbglog.h"

int glob_bTraceEnabled = 0;

int main() {
    int ulBytes = 12;

    printf("before!\n");

    pgdebug("Test, you need to debug something...");

    pgerror("malloc failed to allocate %i bytes", ulBytes);

    printf("after!\n");
    return 0;

}
