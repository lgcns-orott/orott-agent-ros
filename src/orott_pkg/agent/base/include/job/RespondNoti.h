#ifndef __RESPOND_NOTI__
#define __RESPOND_NOTI__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

typedef struct t_RespondNoti    RespondNoti;
struct t_RespondNoti {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;
    
    int label;
    char *command;
    char *rqi;
    char *conn;
};

RespondNoti *RespondNoti_getInstance(RA_Config *config, JobScheduler *scheduler, const char *arg);

#endif
