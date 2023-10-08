
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

public:
    // RobotManagerBase(/* args */);
    // ~RobotManagerBase();
    void init_config_output_srv(ros::NodeHandle *nh);
    bool ConfigOutputCallback(std_srvs::SetBoolRequest &req, std_srvs::SetBoolResponse &response);
};

class RobotManagerMobile : public RobotManagerBase{
private:
    std::string odometry_topic="/robot1/odom";
    ros::Subscriber odom_subscriber;
    float current_x_position = 0.0;
    float current_y_position = 0.0;
public:
    RobotManagerMobile(ros::NodeHandle *nh,std::string odom_topic);
    void init_odom_subscriber(ros::NodeHandle *nh);
    void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);
};


#endif