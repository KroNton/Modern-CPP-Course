
#ifndef BASE_ROBOT_MANAGER_H
#define BASE_ROBOT_MANAGER_H

#include <ros/ros.h>
#include <std_srvs/SetBool.h>
#include <nav_msgs/Odometry.h>

class RobotManagerBase
{
private:
   
   ros::ServiceServer config_output_srv;

protected:
    bool output_enabled=false;
    std::string robot_name="Kronton Robot";
    std::string robot_location="Emeryville, California";



public:
    // RobotManagerBase(/* args */);
    // ~RobotManagerBase();
    void init_config_output_srv(ros::NodeHandle *nh);
    bool ConfigOutputCallback(std_srvs::SetBoolRequest &req, std_srvs::SetBoolResponse &response);
    virtual void displayRobotDetails();
};



#endif