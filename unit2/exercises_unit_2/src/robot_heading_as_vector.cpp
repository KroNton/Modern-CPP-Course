#include "nav_msgs/Odometry.h"
#include "robot_commander/robot_commander.h"
#include <ros/ros.h> 
#include <sstream> 
#include <iostream> 
#include <vector>

int main(int argc, char **argv)
{
  int count;
  std::vector<float> heading;
  ros::init(argc, argv, "heading_vector");
  RobotCommander robot;
  robot.move_in_circles();
  std::cout<<"enter the number of values to store "<<std::endl;
  std::cin>>count;
  
  
  for (size_t i = 0; i < count; i++)
  {
    ros::Duration(1).sleep();
    heading.push_back(robot.get_heading());
    std::cout << "Collecting heading value: " << robot.get_heading()<<std::endl;
  }

  robot.stop_moving();
for ( const float& i:heading)
{
  std::cout << i <<" ";
}
std::cout<<std::endl;


  return 0;
}