#ifndef __REPORTER__
#define __REPORTER__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

#define MAX_MEMBER  32

typedef struct t_Reporter    Reporter;
struct t_Reporter {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;

    int label;
    int member[MAX_MEMBER];
    int interval;
};

Reporter *Reporter_getInstance(RA_Config *config, JobScheduler *scheduler, const char *arg);

#endif
