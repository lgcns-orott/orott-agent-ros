#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
#include <math.h>

extern "C" {
  #include <json-c/json.h>
}

class Robot {
    
private:
    double cx;
    double cy;
    double dx;
    double dy;
    int speed;
    double rotate;
    
public:
    void setCurLoc(double x, double y);
    void setDestLoc(double x, double y);
    void getCurLoc(double *x, double *y);
    void setRotate(double rot);
    double getRotate();
    
    Robot() {
        
        this->cx = 0;
        this->cy = 0;
        this->dx = 0;
        this->dy = 0;
        this->speed = 1;
        this->rotate = 0;
    }
    
    Robot(double _x, double _y, int _speed) {
        this->cx = _x;
        this->cy = _y;
        this->dx = _x;
        this->dy = _y;
        this->speed = _speed;
        this->rotate = 0;
    }
};

void Robot::setCurLoc(double _cx, double _cy) {
    cx = _cx;
    cy = _cy;
}

void Robot::setDestLoc(double _dx, double _dy) {
    dx = _dx;
    dy = _dy;
}

void Robot::getCurLoc(double *_cx, double *_cy) {

    if(fabs(this->cx - this->dx) < this->speed) {
        this->cx = this->dx;
    }
    else {
        if ((this->cx - this->dx) < 0) {
            this->cx += this->speed;
        }
        else {
            this->cx -= this->speed;
        }
    }
    
    if(fabs(this->cy - this->dy) < speed) {
        this->cy = this->dy;
    }
    else {
        if ((this->cy - this->dy) < 0) {
            this->cy += this->speed;
        }
        else {
            this->cy -= this->speed;
        }
    }
    *_cx = this->cx;
    *_cy = this->cy;
}

void Robot::setRotate(double rot) {
    this->rotate = rot;
}

double Robot::getRotate() {
    return this->rotate;
}


Robot* robot = new Robot(110, 110, 2);

void robotCallBack(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("sub msg : \n%s", msg->data.c_str());

  struct json_object *jobj, *jid, *jdata;
  jobj = json_tokener_parse((char *)msg->data.c_str());
  
  json_object_object_get_ex(jobj, "id", &jid);
  if (json_object_get_type(jid) == json_type_null) {
    json_object_put(jobj);
    return ;
  }
  
  if(strcmp("RobotLocation", json_object_get_string(jid)) == 0) {
    struct json_object *jxloc, *jyloc;
    json_object_object_get_ex(jobj, "data", &jdata);
    json_object_object_get_ex(jdata, "x", &jxloc);
    json_object_object_get_ex(jdata, "y", &jyloc);
    double dx = json_object_get_double(jxloc);
    double dy = json_object_get_double(jyloc);
    
    robot->setDestLoc(dx, dy);
  }
  else if(strcmp("Rotate", json_object_get_string(jid)) == 0) {
    robot->setRotate(0.1);
  }
  else if(strcmp("Stop", json_object_get_string(jid)) == 0) {
    robot->setRotate(0);
  }
  else {
    ROS_INFO("CANNOT parse command : \n%s", msg->data.c_str());
  }
}


int main(int argc, char **argv)
{

  ros::init(argc, argv, "simulator");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("orott_sub", 1000);
  ros::Publisher rotater_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ros::Subscriber sub = n.subscribe("orott_pub", 100, robotCallBack);
  ros::Rate loop_rate(1);

  geometry_msgs::Twist tMsg;

  std_msgs::String msg;

  ROS_INFO("Hello ROS Simulator");

  double* tx = new double;
  double* ty = new double;

  while (ros::ok())
  {
    std::stringstream ss;
    robot->getCurLoc(tx, ty);

    ss << "{ \"RobotLocation\": {\"x\": " << *tx << ", \"y\": " << *ty << "} }";
    msg.data = ss.str();
    tMsg.angular.z = robot->getRotate();

    ROS_INFO("pub msg : \n%s", msg.data.c_str());

    chatter_pub.publish(msg);
    rotater_pub.publish(tMsg);

    ros::spinOnce();

    loop_rate.sleep();
      
  }


  return 0;
}