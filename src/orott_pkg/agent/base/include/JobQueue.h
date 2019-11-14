#ifndef __JOB_QUEUE_H__
#define __JOB_QUEUE_H__

#include "RspAgent.h"
#include "job/Job.h"

typedef struct t_JobQueueItem   JobQueueItem;
struct t_JobQueueItem {
    int time;
    Job *job;

    void (*destroy)(JobQueueItem *item);
};

JobQueueItem *JobQueueItem_getInstance(int delay, Job *job);

typedef struct t_JObQueue   JobQueue;
struct t_JObQueue {
    int size;
    JobQueueItem **queue; // Circular queue
    int sIndex;
    int eIndex;

    RspError (*addJob)(JobQueue *queue, Job *job);
    RspError (*addDelayedJob)(JobQueue *queue, int delay, Job *job); /* delay 는 초 단위 */
    RspError (*removeItems)(JobQueue *queue);
    Job *(*getJob)(JobQueue *queue);
    void (*destroy)(JobQueue *queue);
};

JobQueue *JobQueue_getInstance();

#endif
