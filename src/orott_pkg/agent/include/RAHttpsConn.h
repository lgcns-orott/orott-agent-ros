#ifndef __RSP_AGENT_HTTPS__
#define __RSP_AGENT_HTTPS__

#include "RspError.h"

typedef struct t_RAHttpsConn   RAHttpsConn;
struct t_RAHttpsConn {
    RspError (*init)(RAHttpsConn *conn);
    RspError (*connect)(RAHttpsConn *conn, const char *path, const char *data, char **response);
};

RAHttpsConn *RAHttpsConn_getInstance();

#endif