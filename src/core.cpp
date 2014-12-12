#include "se.h"
#include <stdlib.h>
#include <stdio.h>

struct _se_context
{
    int val;
};

static se_context s_context;

SHARED_EXPORT void se_init()
{
    printf("Initializing...\n");
    s_context = (se_context)malloc(sizeof(_se_context));
    s_context->val = 5;
}

SHARED_EXPORT se_context se_get_context()
{
    printf("se_get_context: %p\n", s_context);
    return s_context;
}

