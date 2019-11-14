#ifndef __RESPOND_RESULT__
#define __RESPOND_RESULT__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

typedef struct t_RespondResult    RespondResult;
struct t_RespondResult {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;

    char *rqi;
    char *conn;
};

RespondResult *RespondResult_getInstance(RA_Config *config, JobScheduler *scheduler, const char *arg);

#endif
