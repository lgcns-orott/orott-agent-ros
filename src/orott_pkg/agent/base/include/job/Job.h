#ifndef __JOB_H__
#define __JOB_H__

#include "RspAgent.h"

typedef enum {
    RUN_ONCE,
    RUN_CONTINUE
} RunMode;

typedef void (*Proc)(void *obj);
typedef struct t_Job    Job;
struct t_Job {
    void (*destroy)(Job *job);
    Proc run;
    RunMode mode;
};

Job *Job_getInstance(Proc run);

#endif
