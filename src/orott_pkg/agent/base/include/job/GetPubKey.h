#ifndef __GET_PUB_KEY__
#define __GET_PUB_KEY__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

typedef struct t_GetPubKey    GetPubKey;
struct t_GetPubKey {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;
};

GetPubKey *GetPubKey_getInstance(RA_Config *config, JobScheduler *scheduler);

#endif
