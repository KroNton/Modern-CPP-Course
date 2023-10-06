#ifndef ROBOT_MANGER_H
#define ROBOT_MANGER_H

#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <string>


class RobotManager {

private:
    float current_x_position ;
    float current_y_position;
    float coord;
    std::string odometry_topic="robot/odom";
    std::string robot_name;
    std::string cmd_vel_topic="/cmd_vel";
    ros::Subscriber odom_subscriber;
    ros::Publisher cmd_vel_publisher;
    geometry_msgs::Twist vel_msg;

    
public:
    static int robot_count;
    RobotManager(ros::NodeHandle *nh,std::string RobotName,std::string CmdVelTopic,std::string OdometryTopic);
    RobotManager(const RobotManager &copy_obj);
    ~RobotManager();
    void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);
    float get_coords(int param);
    std::string get_robot_name();
    void move_forward(int seconds);
    void move_backward(int seconds);
    void turn(std::string clock, int n_secs);
  
    

};

#endif