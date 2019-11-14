#ifndef __MQTT_INIT__
#define __MQTT_INIT__

#include "job/Job.h"
#include "RA_Config.h"
#include "JobScheduler.h"

typedef struct t_MqttInit    MqttInit;
struct t_MqttInit {
    Job super; // Don't change the position
    RA_Config *config;
    JobScheduler *scheduler;
};

MqttInit *MqttInit_getInstance(RA_Config *config, JobScheduler *scheduler);

#endif
