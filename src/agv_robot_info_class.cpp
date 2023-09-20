#include "robot_info/agv_robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <ros/ros.h>

AGVRobotInfo::AGVRobotInfo(std::string robot_description,
                           std::string serial_number, std::string ip_address,
                           std::string firmware_version,
                           std::string maximum_payload)
    : RobotInfo(robot_description, serial_number, ip_address, firmware_version),
      maximum_payload(maximum_payload) {}

void AGVRobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg;
  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number: " + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version: " + firmware_version;
  msg.data_field_05 = "maximum_payload: " + maximum_payload;

  pub.publish(msg);
  ROS_INFO("After publish v2");
}
