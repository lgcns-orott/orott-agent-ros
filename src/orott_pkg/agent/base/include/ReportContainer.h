#ifndef __REPORT_CONTAINER__
#define __REPORT_CONTAINER__

#define MAX_ITEM  64
// enum {
//     REPORT_CONTAINER_SW_INFO,
//     REPORT_CONTAINER_ADMIN_MODE,
//     REPORT_CONTAINER_ROBOT_LOCATION,
//     REPORT_CONTAINER_WAITING_INFO,
//     REPORT_CONTAINER_BATTERY,
//     REPORT_CONTAINER_POWER_MODE,
//     REPORT_CONTAINER_DRIVING_PART,
//     REPORT_CONTAINER_ROBOT_STATUS,
//     REPORT_CONTAINER_EVENT,
//     REPORT_CONTAINER_TASK,
//     REPORT_CONTAINER_PSYNC,
//     REPORT_CONTAINER_RSYNC,
//     REPORT_CONTAINER_FUNCTION,
//     REPORT_CONTAINER_INVALID
// };

typedef struct t_RCItem RCItem;
struct t_RCItem {
    char label[32];
    char path[64];
};

typedef struct t_ReportContainer            ReportContainer;
struct t_ReportContainer {

    int itemLength;
    RCItem items[MAX_ITEM];

    void (*destroy)(ReportContainer *containers);
    int (*findContainer)(ReportContainer *containers, const char *label);
    char *(*getLabel)(ReportContainer *containers, int idx);
    char *(*getPath)(ReportContainer *containers, int idx);
};

ReportContainer *ReportContainer_getInstance(char *arg);

#endif
