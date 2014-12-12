#include "se.h"
#include <stdio.h>

void se_util_run()
{
    se_context context = se_get_context();
    printf("se_util_run: %p : %d\n", context, *((int*)context));
}
