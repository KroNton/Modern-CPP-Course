#include "nav_msgs/Odometry.h"
#include "robot_commander/robot_commander.h"
#include <ros/ros.h> 
#include <sstream> 
#include <iostream> 
#include<map>
int main(int argc, char **argv)
{
  int count;
  std::map<int, std::pair<float,float>> polygonVertices;
  std::map<int, std::pair<float,float>> ::iterator it;
 
  ros::init(argc, argv, "polygon_vertices");
  RobotCommander robot;

  robot.move_forward(3);
  robot.turn(0.45, 2); 
  polygonVertices[1]=std::make_pair(robot.get_x_position(),robot.get_y_position());

  robot.move_forward(3);
  robot.turn(0.45, 2); 
  polygonVertices[2]=std::make_pair(robot.get_x_position(),robot.get_y_position());

  robot.move_forward(3);
  robot.turn(0.45, 2);
  polygonVertices[3]=std::make_pair(robot.get_x_position(),robot.get_y_position());

  robot.move_forward(3);
  robot.turn(0.45, 2);
  polygonVertices[4]=std::make_pair(robot.get_x_position(),robot.get_y_position());

  robot.stop_moving();

    
  std::cout << "The elements of vertex are : " <<std::endl;  
  for(it=polygonVertices.begin();it!=polygonVertices.end();it++){
      std::cout<<"("<<it->second.first << "," << it->second.second <<")"<<" -> "<<it->first<<std::endl;
  }  




  return 0;
}