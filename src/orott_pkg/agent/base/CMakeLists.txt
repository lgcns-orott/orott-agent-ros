CMAKE_MINIMUM_REQUIRED ( VERSION 3.5 )

PROJECT( librspagent )

SET ( LIBRARY_OUTPUT_DIRECTORY ../out/lib )

INCLUDE_DIRECTORIES ( include ../include ../external/json-c/include )

set ( CMAKE_BUILD_TYPE Debug )

SET ( SRC_FILES 
    common/RA_Config.c
    common/RA_Log.c
    common/RspAgent.c
    JobQueue/Job.c 
    JobQueue/JobQueue.c 
    JobQueue/JobHandler.c
    JobQueue/JobScheduler.c
    Jobs/GetPubKey.c
    Jobs/SysInit.c
    Jobs/Register.c
    Jobs/SignIn.c
    Jobs/PSync.c
    Jobs/RSync.c
    Jobs/TSync.c
    Jobs/MqttInit.c
    Jobs/ReporterMaker.c
    Jobs/Reporter.c
    Jobs/RespondNoti.c
    Jobs/RespondResult.c
    common/ReportContainer.c
    Jobs/EventProc.c
    Jobs/NotifyProc.c )

ADD_LIBRARY( rspagent SHARED ${SRC_FILES} )
