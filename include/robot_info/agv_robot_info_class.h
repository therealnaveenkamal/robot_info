#pragma once
#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

class AGVRobotInfo : public RobotInfo {

public:
  AGVRobotInfo(std::string robot_description, std::string serial_number,
               std::string ip_address, std::string firmware_version,
               std::string maximum_payload);
  void publish_data() override;

protected:
  std::string maximum_payload;
};