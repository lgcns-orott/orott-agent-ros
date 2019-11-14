#ifndef __REGISTER__
#define __REGISTER__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

typedef struct t_Register    Register;
struct t_Register {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;
};

Register *Register_getInstance(RA_Config *config, JobScheduler *scheduler);

#endif
