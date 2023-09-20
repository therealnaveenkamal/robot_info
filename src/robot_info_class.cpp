
#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <ros/ros.h>

RobotInfo::RobotInfo(std::string robot_description, std::string serial_number,
                     std::string ip_address, std::string firmware_version)
    : robot_description(robot_description), serial_number(serial_number),
      ip_address(ip_address), firmware_version(firmware_version) {

  pub = nh.advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 1000);
  ROS_INFO("Before publish");
}

void RobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg;
  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number: " + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version: " + firmware_version;
  pub.publish(msg);

  ROS_INFO("After publish");
}