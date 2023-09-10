#include "nav_msgs/Odometry.h"
#include <ros/ros.h>
#include "my_robot_manager/robot_manager.h"

RobotManager::RobotManager(ros::NodeHandle *nh){

    odom_subscriber= nh->subscribe(odometry_topic,50,&RobotManager::odom_callback,this);

    
}

void RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &odom_msg){
    current_x_position= odom_msg->pose.pose.position.x;
    current_y_position= odom_msg->pose.pose.position.y;
    ROS_INFO("Position (x,y): %lf , %lf", current_x_position, current_y_position);
}



