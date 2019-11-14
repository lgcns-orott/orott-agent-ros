#ifndef __TILE_MAP_SYNC__
#define __TILE_MAP_SYNC__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

typedef struct t_TSync    TSync;
struct t_TSync {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;
};

TSync *TSync_getInstance(RA_Config *config, JobScheduler *scheduler);

#endif
