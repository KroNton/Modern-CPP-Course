#include <ros/ros.h>
#include "robot_manager_inheritance/base_robot_manager.h"



int main(int argc, char  **argv)
{
    ros::init(argc, argv, "robot_manager");
    ros::NodeHandle nh;
    RobotManagerMobile robot(&nh);
    ros::spin();
    return 0;
}
