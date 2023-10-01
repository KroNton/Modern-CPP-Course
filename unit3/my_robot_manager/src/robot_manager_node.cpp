#include <ros/ros.h>
#include "my_robot_manager/robot_manager.h"



int main(int argc, char  **argv)
{
    ros::init(argc, argv, "robot_manager");
    ros::NodeHandle nh;
    ros::Rate loop_rate(1);
    RobotManager rm1(&nh,"turtlebot3_1","/odom");
    RobotManager rm2(&nh,"turtlebot3_2","turtlebot/odom");
  while (ros::ok()) {
    float robot1_x=rm1.get_coords(1);
    float robot1_y=rm1.get_coords(2);
    float robot2_x=rm2.get_coords(1);
    float robot2_y=rm2.get_coords(2);
    ROS_INFO("%s Position (x,y): %lf , %lf",rm1.get_robot_name().c_str(),robot1_x , robot1_y);
    ROS_INFO("%s Position (x,y): %lf , %lf",rm2.get_robot_name().c_str(), robot2_x , robot2_y);
    ros::spinOnce();
    loop_rate.sleep();
  }
    
    return 0;
}
