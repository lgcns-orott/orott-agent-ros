#ifndef __NOTIFY_PROCESS__
#define __NOTIFY_PROCESS__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

typedef struct t_NotifyProc    NotifyProc;
struct t_NotifyProc {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;

    char *notification;
};

NotifyProc *NotifyProc_getInstance(RA_Config *config, JobScheduler *scheduler, const char *arg);

#endif
