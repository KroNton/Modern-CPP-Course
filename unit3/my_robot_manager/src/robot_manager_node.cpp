#include <ros/ros.h>
#include "my_robot_manager/robot_manager.h"

struct robot_position{

float x;
float y;

};


int main(int argc, char  **argv)
{
    ros::init(argc, argv, "robot_manager");
    ros::NodeHandle nh;
    RobotManager rm1(&nh,"turtlebot3_1","/cmd_vel","/odom");
    robot_position robot1_pose;

    
    
    rm1.move_forward(2);

    robot1_pose.x=rm1.get_coords(1);
    robot1_pose.y=rm1.get_coords(2);

    std::cout<< "Current position of the first robot"<<std::endl;
    ROS_INFO("%s Position (x,y): %lf , %lf",rm1.get_robot_name().c_str(),robot1_pose.x , robot1_pose.y);
    
    rm1.move_backward(2);

    RobotManager robot_copy=rm1;
    
    
    robot1_pose.x=robot_copy.get_coords(1);
    robot1_pose.y=robot_copy.get_coords(2);
    std::cout<< "Final position of the first robot"<<std::endl;
    ROS_INFO("%s Position (x,y): %lf , %lf",rm1.get_robot_name().c_str(),robot1_pose.x , robot1_pose.y);

    
  
    return 0;
}
