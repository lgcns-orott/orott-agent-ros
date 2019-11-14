#ifndef __RSP_ERROR_H__
#define __RSP_ERROR_H__

typedef enum {
    RSP_AGENT_ERR_OK = 0,
    RSP_AGENT_ERR_GENERAL = -1,
    RSP_AGENT_ERR_MEMORY = -2,
    RSP_AGNET_ERR_JOB_QUEUE_FULL = -3,
    RSP_AGENT_ERR_ERR
} RspError;

#endif
