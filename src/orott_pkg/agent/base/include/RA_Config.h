#ifndef __RA_CONFIG__
#define __RA_CONFIG__

#include "RspAgent.h"
#include "ReportContainer.h"

#define MAX_MACHINE_ID  32
#define MAX_UUID        32
#define MAX_PUBLIC_KEY  1024
#define MAX_PRIVATE_KEY 2048
#define MAX_SYMMETRIC_KEY 32
#define MAX_AEID        32
#define MAX_TOKEN       32
#define MAX_PSYNC       32 * 1024
#define MAX_FILE_NAME   2048

typedef struct raConfig {
    // persist
    char machineId[MAX_MACHINE_ID + 1];
    char uuid[MAX_UUID + 1];
    char serverkey[MAX_PUBLIC_KEY];
    char publickey[MAX_PUBLIC_KEY];
    char symmetrickey[MAX_SYMMETRIC_KEY];
    char privatekey[MAX_PRIVATE_KEY];
    char aeid[MAX_AEID + 1];
    char psyncData[MAX_PSYNC];

    // no save
    char token[MAX_TOKEN + 1];
    ReportContainer *reportContainer;
    RASysInfo *sysInfo;
    RASecure *secure;
    RAHttpsConn *httpsConn;
    RAMqttConn *mqttConn;
    NotifyCallback *notifyCallback; // to robot device

    char configFile[MAX_FILE_NAME];
} RA_Config;

void RA_Config_load(RA_Config *config);
void RA_Config_save(RA_Config *config);

#endif
