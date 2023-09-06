#include "nav_msgs/Odometry.h"
#include "robot_commander/robot_commander.h"
#include <ros/ros.h> 
#include <sstream> 
#include <iostream> 
#include<set>
int main(int argc, char **argv)
{
  int count;
  std::set<std::pair<float, float>> polygonVertices;
  std::set<std::pair<float, float>> ::iterator it;
  ros::init(argc, argv, "polygon_vertices");
  RobotCommander robot;

  polygonVertices.insert({robot.get_x_position() , robot.get_y_position()});
  robot.move_forward(3);
  polygonVertices.insert({robot.get_x_position() , robot.get_y_position()});
  robot.move_backwards(2);
  polygonVertices.insert({robot.get_x_position() , robot.get_y_position()});
  robot.turn(0.5, 2);
  polygonVertices.insert({robot.get_x_position() , robot.get_y_position()});
  robot.stop_moving();
  polygonVertices.insert({robot.get_x_position() , robot.get_y_position()});
    
  std::cout << "The elements of vertex are : " <<std::endl;  
  for(it=polygonVertices.begin();it!=polygonVertices.end();it++){
      std::cout<< "("<<it->first << "," << it->second <<")"<<std::endl;
  }  




  return 0;
}