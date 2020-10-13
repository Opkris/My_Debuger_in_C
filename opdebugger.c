#include <stdio.h>
#include <stdlib.h>
#include "include/pgdbglog.h"

int glob_bTraceEnabled = 1;

int main() {
    int ulBytes = 12;

    pgdebug("Test, you need to debug something...");

    pgerror("malloc failed to allocate %i bytes", ulBytes);

    printf("hurray, something happened!\n");
    return 0;

}
