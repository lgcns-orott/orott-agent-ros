#ifndef __RSP_AGENT_WRAPPER__
#define __RSP_AGENT_WRAPPER__

#include "RspError.h"
#include "RspAgent.h"

typedef struct t_Wrapper   Wrapper;
struct t_Wrapper {

    RspError (*init)(Wrapper* wrapper, NotifyCallback* _notifyCallback, RASysInfo* _sysInfo);
    RspError (*notify)(const char *arg);
    RspError (*respond)(Wrapper* wrapper, const char *arg);
    
    RspAgent *agent;
};

Wrapper *Wrapper_getInstance();

#endif
