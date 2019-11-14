#ifndef __RAJOB_SYSTEM_INIT_KEY__
#define __RAJOB_SYSTEM_INIT_KEY__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

typedef struct t_SysInit    SysInit;
struct t_SysInit {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;
};

SysInit *SysInit_getInstance(RA_Config *config, JobScheduler *scheduler);

#endif
