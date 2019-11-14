#ifndef __JOB_HANDLER_H__
#define __JOB_HANDLER_H__

#include "RspAgent.h"
#include "job/Job.h"
#include "JobQueue.h"

typedef void*   JobHandlerContext;

typedef struct t_JobHandler JobHandler;
struct t_JobHandler {
    JobQueue *queue;
    int status;

    void (*destroy)(JobHandler *handler);

    RspError (*addJob)(JobHandler *handler, Job *job);
    RspError (*addDelayedJob)(JobHandler *handler, int delay, Job *job); /* delay 는 초 단위 */

    void (*run)(JobHandler *handler);
    void (*stop)(JobHandler *handler);
};

JobHandler *JobHandler_getInstance(int queueSize);

#endif
