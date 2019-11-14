This is a module for Orott to control ROS robots.

## Requirements

- [ROS Kinetic](http://wiki.ros.org/kinetic/Installation/Ubuntu) - It was not tested in other versions.
- ARMHF core - The Libraries were built by ARMHF core

## SetUp

To Register your robot at Orott, You should create Robot Model and Robot Unit at [Orott Portal](https://saas.orott-lgcns.com/) first.

Next, Set Mac Address at `orott_controller.cpp`
```
void runAgent()
{
  char macAddr[] = "ABCDEFGHIJKL";
  sysInfo->setMacAddress(sysInfo, macAddr);
}
```

## Make Actions

Orott_controller node publish data on topic `/orott_pub`.
If you want modify the topic name, you can edit at `orott_controller.cpp`. Else, make another node that manage orott and robot.

Sample source code is `robot_sim.cpp`. In this Sample, [TurtleBot3](https://www.turtlebot.com/) is used for test. You can make the actions according to command name.
```
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
```


## Build

This project uses catkin_make
```
catkin_make
```

## RUN

There are two launch files included.
* `orott_sample` - run orott_controller and robot_sample
* `orott_controller` - run orott_controller only
```
source devel/setup.bash
roslaunch orott_pkg orott_sample.launch
```

## License

GPLv2 License

## How to Contribute

Create Issues and Pull requests against this Repository on Github