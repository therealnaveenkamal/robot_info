#include "robot_info/robot_info_class.h"
#include "ros/init.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");

  ROS_INFO("Object Initialized");
  RobotInfo ri("Mir100", "567A359", "169.254.5.180", "3.5.8");

  ros::Rate rate(2);

  ROS_INFO("Publishing Data");
  while (ros::ok()) {
    ri.publish_data();
    ros::spinOnce();
    rate.sleep();
  }
}