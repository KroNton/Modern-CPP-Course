#include "nav_msgs/Odometry.h"
#include "robot_commander/robot_commander.h"
#include <ros/ros.h> 
#include <sstream> 
#include <iostream> 
#include <deque>
int main(int argc, char **argv)
{
  int count;
  std::deque<float> headings;
  ros::init(argc, argv, "heading_deque");
  RobotCommander robot;
  robot.move_in_circles();
  std::cout<<"enter the number of values to store "<<std::endl;
  std::cin>>count;
  
  
  for (size_t i = 0; i < count; i++)
  {
    ros::Duration(1).sleep();
    headings.push_front(robot.get_heading());
    std::cout << "Collecting heading value: " << robot.get_heading()<<std::endl;
  }
std::cout<<std::endl;

std::cout << "Displaying saved data " <<std::endl;


for (int i = 0; i < count; i++)
{
   std::cout<<"Heading value " << i <<": "<<headings.at(i)<<std::endl;
}




  robot.stop_moving();

  return 0;
}