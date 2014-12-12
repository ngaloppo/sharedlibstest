#include "se.h"
#include "context.h"
#include <stdlib.h>
#include <stdio.h>

static ext_context s_context = 0;

void se_init()
{
    printf("Initializing...\n");
    s_context = create_context();
}

ext_context se_get_context()
{
    printf("se_get_context: %p\n", s_context);
    return s_context;
}

