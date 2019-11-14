#ifndef __RSP_AGENT_SYS_INFO__
#define __RSP_AGENT_SYS_INFO__

#include "RspError.h"

typedef struct t_RASysInfo   RASysInfo;
struct t_RASysInfo {
    
    char* mac;
    double xLoc;
    double yLoc;
    int batteryPercentage;
    
    RspError (*getStoragePath)(RASysInfo *sysInfo, char *path);
    RspError (*getMacAddress)(RASysInfo *sysInfo, char *mac);
    RspError (*getUuid)(RASysInfo *sysInfo, char *uuid);
    RspError (*getLocation)(RASysInfo *sysInfo, char *location);
    RspError (*getBatteryStatus)(RASysInfo *sysInfo, char *status);
    RspError (*setBatteryPercentage)(RASysInfo *sysInfo, int bp);
    RspError (*setMacAddress)(RASysInfo *sysInfo, char *mac);
    RspError (*setLocation)(RASysInfo *sysInfo, double xloc, double yloc);
};

RASysInfo *RASysInfo_getInstance();

#endif
