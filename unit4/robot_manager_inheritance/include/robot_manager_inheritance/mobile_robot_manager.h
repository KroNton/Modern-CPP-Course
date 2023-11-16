
#ifndef MOBILE_ROBOT_MANAGER_H
#define MOBILE_ROBOT_MANAGER_H

#include <ros/ros.h>
#include <std_srvs/SetBool.h>
#include <nav_msgs/Odometry.h>
#include "robot_manager_inheritance/base_robot_manager.h"


class RobotManagerMobile : public RobotManagerBase{
private:
    std::string odometry_topic="/robot1/odom";
    ros::Subscriber odom_subscriber;
    float current_x_position = 0.0;
    float current_y_position = 0.0;
    float battery_charge_level= 0.55;
    std::string type_of_battery="Lead acid batteries";

public:
    RobotManagerMobile(ros::NodeHandle *nh,std::string odom_topic);
    void init_odom_subscriber(ros::NodeHandle *nh);
    void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);
    void displayRobotDetails();
};


#endif