#ifndef __EVENT_PROCESS__
#define __EVENT_PROCESS__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

typedef struct t_EventProc    EventProc;
struct t_EventProc {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;

    char *event;
};

EventProc *EventProc_getInstance(RA_Config *config, JobScheduler *scheduler, const char *arg);

#endif
