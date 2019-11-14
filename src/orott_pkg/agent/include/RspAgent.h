#ifndef __RSP_AGENT_H__
#define __RSP_AGENT_H__

#define MAX_MACHINE_ID  32
#define MAX_UUID        32
#define MAX_AEID        32
#define MAX_TOKEN       32

#include "RspError.h"
#include "RASysInfo.h"
#include "RASecure.h"
#include "RAHttpsConn.h"
#include "RAMqttConn.h"

typedef RspError (NotifyCallback)(const char *arg); // {"id": "notification id", "data": {notification data}}

typedef struct t_RspAgent   RspAgent;
struct t_RspAgent {
    void *context;

    void (*destroy)(RspAgent *agent);
    RspError (*start)(RspAgent *agent);
    RspError (*registerRASysInfo)(RspAgent *agent, RASysInfo *sysInfo);
    RspError (*registerRASecure)(RspAgent *agent, RASecure *secure);
    RspError (*registerRAHttpsConn)(RspAgent *agent, RAHttpsConn *conn);
    RspError (*registerRAMqttConn)(RspAgent *agent, RAMqttConn *conn);
    
    char *(*getAeid)(RspAgent *agent);
    RspError (*sendEvent)(RspAgent *agent, char *arg); // {"id": "event id", "data": {event data}}
    RspError (*registerNotifyCallback)(RspAgent *agent, NotifyCallback *cblk);
    RspError (*notify)(RspAgent *agent, char *notification);
    RspError (*respond)(RspAgent *agent, char *response);
};
RspAgent *RspAgent_getInstance(char *configFile);

#endif
