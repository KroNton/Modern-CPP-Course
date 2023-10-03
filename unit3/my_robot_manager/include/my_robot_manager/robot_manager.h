#ifndef ROBOT_MANGER_H
#define ROBOT_MANGER_H

#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <string>


class RobotManager {

private:
    float current_x_position = 0.0;
    float current_y_position = 0.0;
    float coord;
    std::string odometry_topic="/robot1/odom";
    std::string robot_name;
    ros::Subscriber odom_subscriber;
    
public:
    RobotManager(ros::NodeHandle *nh,std::string name,std::string odom_topic);
    void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);
    float get_coords(int param);
    std::string get_robot_name();
    static int robot_count;
    

};

#endif