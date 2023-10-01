#include "nav_msgs/Odometry.h"
#include <ros/ros.h>
#include "my_robot_manager/robot_manager.h"

//initialize robot_count static class member
int RobotManager::robot_count=0;

RobotManager::RobotManager(ros::NodeHandle *nh,std::string name,std::string odom_topic){
    odometry_topic=odom_topic;
    robot_name=name;
    odom_subscriber= nh->subscribe(odometry_topic,50,&RobotManager::odom_callback,this);
    robot_count++;
    ROS_INFO("Robot %d created", robot_count);
   
}

void RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &odom_msg){
   
   current_x_position= odom_msg->pose.pose.position.x;
   current_y_position= odom_msg->pose.pose.position.y;
    

}

std::string RobotManager::get_robot_name(){
    return robot_name;
}

float RobotManager::get_coords(int param){

  if (param == 1) {
    return this->current_x_position;
  } else if (param == 2) {
    return this->current_y_position;
  } 
  return 0;
}


