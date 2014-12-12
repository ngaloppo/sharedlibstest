#include "se.h"
#include <stdio.h>

int main()
{
    se_init();
    ext_context context = se_get_context();
    printf("app: %p\n", context);

    se_util_run();

    return 0;
}


