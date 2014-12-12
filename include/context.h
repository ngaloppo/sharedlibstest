#ifndef __context_h__
#define __context_h__

typedef struct _ext_context * ext_context;

ext_context create_context();
int use_context(ext_context c);

#endif
