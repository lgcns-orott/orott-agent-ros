#ifndef __REPORTER_MAKER__
#define __REPORTER_MAKER__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

typedef struct t_ReporterMaker    ReporterMaker;
struct t_ReporterMaker {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;
};

ReporterMaker *ReporterMaker_getInstance(RA_Config *config, JobScheduler *scheduler);

#endif
