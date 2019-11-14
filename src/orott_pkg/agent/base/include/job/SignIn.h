#ifndef __SIGN_IN__
#define __SIGN_IN__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

typedef struct t_SignIn    SignIn;
struct t_SignIn {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;
};

SignIn *SignIn_getInstance(RA_Config *config, JobScheduler *scheduler);

#endif
