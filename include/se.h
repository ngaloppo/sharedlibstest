#ifndef __se_h__
#define __se_h__

//#define SHARED_EXPORT extern "C"
#define SHARED_EXPORT

typedef struct _se_context * se_context;

SHARED_EXPORT void se_init();
SHARED_EXPORT se_context se_get_context();

void se_util_run();

#endif // __se_h__

