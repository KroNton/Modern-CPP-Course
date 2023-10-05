#include <ros/ros.h>
#include "my_robot_manager/robot_manager.h"



int main(int argc, char  **argv)
{
    ros::init(argc, argv, "robot_manager");
    ros::NodeHandle nh;
    RobotManager rm1(&nh,"turtlebot3_1","/cmd_vel","/odom");

    float robot1_x=rm1.get_coords(1);
    float robot1_y=rm1.get_coords(2);
    ROS_INFO("%s Position (x,y): %lf , %lf",rm1.get_robot_name().c_str(),robot1_x , robot1_y);


    
    return 0;
}
