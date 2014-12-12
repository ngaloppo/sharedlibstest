#include "context.h"
#include <stdlib.h>
#include <stdio.h>

struct _ext_context
{
    int val;
};

ext_context create_context()
{
    ext_context c = (ext_context)malloc(sizeof(_ext_context));
    c->val = 5;
    return c;
}

int use_context(ext_context c)
{
    if (!c)
    {
        printf("ERROR: invalid context\n");
        return -1;
    }

    printf("Using context: %p\n", c);
    return 0;
}
