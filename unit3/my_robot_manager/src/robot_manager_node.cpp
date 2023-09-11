#include <ros/ros.h>
#include "my_robot_manager/robot_manager.h"



int main(int argc, char  **argv)
{
    ros::init(argc, argv, "robot_manager");
    ros::NodeHandle nh;
    RobotManager robot_manger(&nh,"turtlebot3","/odom");
    ros::spin();
    return 0;
}
