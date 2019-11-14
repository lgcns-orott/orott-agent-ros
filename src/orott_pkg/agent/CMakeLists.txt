CMAKE_MINIMUM_REQUIRED ( VERSION 3.5 )

PROJECT( rspagent )

INCLUDE_DIRECTORIES ( include external/json-c/include external/paho.mqtt.c/include )

LINK_DIRECTORIES ( base external/json-c/lib external/paho.mqtt.c/lib )
LINK_LIBRARIES ( rspagent json-c curl ssl crypto paho-mqtt3cs )

set ( CMAKE_BUILD_TYPE Debug )

SET ( SRC_FILES
    src/Wrapper.c
    src/RASysInfo.c
    src/RASecure.c
    src/RAHttpsConn.c
    src/RAMqttConn.c    
)

ADD_LIBRARY( orottagent SHARED ${SRC_FILES} )
