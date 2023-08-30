#include "nav_msgs/Odometry.h"
#include "robot_commander/robot_commander.h"
#include <ros/ros.h> 
#include <sstream> 
#include <iostream> 


int main(int argc, char **argv)
{
  ros::init(argc, argv, "odom_listener");
  RobotCommander robot;
  float  robot_pose[3];

  robot_pose[0]=robot.get_x_position();
  robot_pose[1]=robot.get_y_position();
  robot_pose[2]=robot.get_z_position();

 for (int i = 0;i < 3; i++)
 {
  std::cout <<*(robot_pose+i) <<std::endl;
 }
 
  return 0;
}