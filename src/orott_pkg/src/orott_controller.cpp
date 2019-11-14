#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <queue>
#include <boost/thread/thread.hpp>

extern "C" {
  #include "Wrapper.h"
  #include <json-c/json.h>
}

static RspError _notifyCallback(const char *arg);
static void _pubMessage(const char *msg);

RASysInfo *sysInfo = RASysInfo_getInstance();
Wrapper *wrp = Wrapper_getInstance();

void runAgent()
{
  ROS_INFO("runAgent");

  char macAddr[] = "388C5070F31F";
  sysInfo->setMacAddress(sysInfo, macAddr);

  wrp->init(wrp, _notifyCallback, sysInfo);
}

RspError _notifyCallback(const char *arg) {

    struct json_object *jobj, *jid, *jdata, *jrqi;

    ros::NodeHandle n;
    ros::Publisher orott_pub = n.advertise<std_msgs::String>("orott_pub", 1000);
    ros::Rate loop_rate(1);

    std::stringstream ss;
    std_msgs::String msg;

    ss << arg;
    msg.data = ss.str();

    // ROS_INFO("publish data : %s\n", msg.data.c_str());

    orott_pub.publish(msg);

    jobj = json_tokener_parse((char *)arg);
    json_object_object_get_ex(jobj, "id", &jid);
    if (json_object_get_type(jid) == json_type_null) {
        json_object_put(jobj);
        return RSP_AGENT_ERR_ERR;
    }
    json_object_object_get_ex(jobj, "rqi", &jrqi);
    if (json_object_get_type(jrqi) == json_type_null) {
        json_object_put(jobj);
        return RSP_AGENT_ERR_ERR;
    }
    struct json_object *rjobj = json_object_new_object();
    json_object_object_add(rjobj, "id", jid);
    json_object_object_add(rjobj, "rqi", jrqi);
    json_object_object_add(rjobj, "conn", json_object_new_string("1"));

    wrp->respond(wrp, json_object_get_string(rjobj));
    
    json_object_put(jobj);

    return RSP_AGENT_ERR_OK;
}

void orottSubscriber(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("received msg: [%s]", msg->data.c_str());

  struct json_object *jobj, *jloc, *jxloc, *jyloc;

  jobj = json_tokener_parse(msg->data.c_str());
  json_object_object_get_ex(jobj, "RobotLocation", &jloc);
  if (json_object_get_type(jloc) == json_type_null) {
      json_object_put(jobj);
      ROS_ERROR("Robot Location is NULL");
  }
  else {
    json_object_object_get_ex(jloc, "x", &jxloc);
    json_object_object_get_ex(jloc, "y", &jyloc);

    sysInfo->setLocation(sysInfo, json_object_get_double(jxloc), json_object_get_double(jyloc));
  }  
}

int main(int argc, char **argv)
{
  ROS_INFO("Hello Orott");

  ros::init(argc, argv, "controller");
  ros::NodeHandle n;
  
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("orott_pub", 1000);
  ros::Subscriber sub = n.subscribe("orott_sub", 1000, orottSubscriber);
  ros::Rate loop_rate(10);

  boost::thread th1(runAgent);
  
  ROS_INFO("Orott Agent is running");

  int count = 0;
  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }

  return 0;
}
