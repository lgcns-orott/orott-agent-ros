#ifndef __JOB_SCHEDULER__
#define __JOB_SCHEDULER__

#include "RspAgent.h"
#include "JobHandler.h"
#include "RA_Config.h"

typedef enum e_JobID {
    JobID_GET_SYS_INFO = 1,
    JobID_GET_PUB_KEY,
    JobID_REGISTER,
    JobID_SIGN_IN,
    JobID_P_SYNC,
    JobID_R_SYNC,
    JobID_T_SYNC,
    JobID_MQTT_INIT,
    JobID_REPORTER_MAKER,
    JobID_REPORTER,
    JobID_EVENT_PROC,
    JobID_NOTIFY_PROC,
    JobID_RESPOND_NOTI,
    JobID_RESPOND_RESULT,
    JobID_INITIAL
} JobID;

typedef struct t_JobScheduler JobScheduler;
struct t_JobScheduler {
    JobHandler *handler;
    RA_Config *config;

    void (*destroy)(JobScheduler *handler);
    RspError (*schedule)(JobScheduler *scheduler, JobID id, const char *arg);
    RspError (*scheduleDelay)(JobScheduler *scheduler, JobID id, const char *arg, int delay);
    void (*start)(JobScheduler *handler);
};

JobScheduler *JobScheduler_getInstance(RA_Config *config, JobHandler *handler);

#endif
