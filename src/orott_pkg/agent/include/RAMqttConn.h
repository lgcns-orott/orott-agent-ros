#ifndef __RSP_AGENT_MQTT__
#define __RSP_AGENT_MQTT__

#include "RspError.h"

typedef struct t_RAMqttConn   RAMqttConn;
struct t_RAMqttConn {
    RspError (*init)(RAMqttConn *conn);
    RspError (*connect)(RAMqttConn *conn);
    RspError (*publish)(RAMqttConn *conn, const char *data);
};

RAMqttConn *RAMqttConn_getInstance();

#endif