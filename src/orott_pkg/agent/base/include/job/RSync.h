#ifndef __RESOURCE_SYNC__
#define __RESOURCE_SYNC__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

typedef struct t_RSync    RSync;
struct t_RSync {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;
};

RSync *RSync_getInstance(RA_Config *config, JobScheduler *scheduler);

#endif
