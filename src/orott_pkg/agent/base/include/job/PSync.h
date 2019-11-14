#ifndef __PROFILE_SYNC__
#define __PROFILE_SYNC__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

typedef struct t_PSync    PSync;
struct t_PSync {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;
};

PSync *PSync_getInstance(RA_Config *config, JobScheduler *scheduler);

#endif
