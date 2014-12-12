#include "se.h"
#include <stdio.h>

void se_util_run()
{
    ext_context c = se_get_context();
    printf("se_util_run: %p : %d\n", c, *((int*)c));
    use_context(c);
}
