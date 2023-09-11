#include <ros/ros.h>
#include "my_robot_manager/robot_manager.h"



int main(int argc, char  **argv)
{
    ros::init(argc, argv, "robot_manager");
    ros::NodeHandle nh;
    RobotManager robot_manger1(&nh,"turtlebot3_1","/odom");
    RobotManager robot_manger2(&nh,"turtlebot3_2","turtlebot/odom");
    ros::spin();
    return 0;
}
