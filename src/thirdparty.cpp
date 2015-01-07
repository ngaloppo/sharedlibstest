#define str(x) #x
#define xstr(x) str(x)
const char * tpGetVersion()
{
    return xstr(TP_VERSION);
}

