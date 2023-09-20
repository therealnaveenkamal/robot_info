#include "robot_info/agv_robot_info_class.h"
#include "robot_info/agv_robot_info_class.h"
#include "ros/init.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_node");

  ROS_INFO("Object Initialized");
  AGVRobotInfo ri("Mir100", "567A359", "169.254.5.180", "3.5.8", "100 Kg");

  ros::Rate rate(2);

  ROS_INFO("Publishing Data");
  while (ros::ok()) {
    ri.publish_data();
    ros::spinOnce();
    rate.sleep();
  }
}