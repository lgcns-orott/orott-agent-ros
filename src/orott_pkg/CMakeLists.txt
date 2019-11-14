cmake_minimum_required(VERSION 2.8.3)
project(orott_pkg)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg message_generation)

################################################
## Declare ROS messages, services and actions ##
################################################

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
# )

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES orott_agent
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

###########
## Build ##
###########

#set_target_properties(original_target
#PROPERTIES OUTPUT_NAME target
#PREFIX "")

include_directories(
    ${catkin_INCLUDE_DIRS}
    agent
    agent/include
    agent/external/json-c/include
    agent/external/paho.mqtt.c/include
)

link_directories(
    ${catkin_INCLUDE_DIRS}/
    agent/
    agent/base/
    agent/external/json-c/lib/
    agent/external/paho.mqtt.c/lib/
)

add_service_files (
  FILES
  orottCommand.srv
)

add_executable(orott_controller src/orott_controller.cpp)
target_link_libraries(orott_controller
    ${catkin_LIBRARIES}
    orottagent
    rspagent
    json-c
    curl
    ssl
    crypto
    paho-mqtt3cs
)

add_executable(orott_listener src/orott_listener.cpp)
target_link_libraries(orott_listener
    ${catkin_LIBRARIES}
)

add_executable(robot_sim src/robot_sim.cpp)
target_link_libraries(robot_sim
    ${catkin_LIBRARIES}
    json-c
)

