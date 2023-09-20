#pragma once
#include <ros/ros.h>

class RobotInfo {

public:
  RobotInfo(std::string robot_description, std::string serial_number,
            std::string ip_address, std::string firmware_version);
  virtual void publish_data();

protected:
  ros::Publisher pub;
  ros::NodeHandle nh;
  std::string robot_description, serial_number, ip_address, firmware_version;
};