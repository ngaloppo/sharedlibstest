#include "mylib.h"
#include "thirdparty.h"

#include <stdio.h>

int main(void)
{
    printf("Third party version: %s\n", tpGetVersion());
    printf("Third party version through mylib: %s\n", mylibGetThirdPartyVersion());

    return 0;
}

