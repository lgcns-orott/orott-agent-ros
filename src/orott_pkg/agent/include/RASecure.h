#ifndef __RSP_AGENT_SECURE__
#define __RSP_AGENT_SECURE__

#include "RspError.h"

typedef struct t_RASecure   RASecure;
struct t_RASecure {
    RspError (*getClientKey)(RASecure *secure, char *privateKey, char *publicKey);
    RspError (*encrypt)(RASecure *secure, const char *data, char *key, char **enc);
    RspError (*decrypt)(RASecure *secure, const char *data, char *key, char **dec);
    RspError (*sign)(RASecure *secure, const char *data, char *key, char **hash);
    RspError (*decryptUsingSymkey)(RASecure *secure, const char *data, char *key, char **dec);
};

RASecure *RASecure_getInstance();

#endif