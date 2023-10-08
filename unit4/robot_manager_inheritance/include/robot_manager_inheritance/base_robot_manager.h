
#ifndef BASE_ROBOT_MANAGER_H
#define BASE_ROBOT_MANAGER_H

#include <ros/ros.h>
#include <std_srvs/SetBool.h>


class RobotManagerBase
{
private:
   bool output_enabled=false;
   ros::ServiceServer config_output_srv;
public:
    // RobotManagerBase(/* args */);
    // ~RobotManagerBase();
    void init_config_output_srv(ros::NodeHandle *nh);
    bool ConfigOutputCallback(std_srvs::SetBoolRequest &req, std_srvs::SetBoolResponse &response);
};




#endif