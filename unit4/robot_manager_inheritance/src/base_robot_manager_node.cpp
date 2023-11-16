#include <ros/ros.h>
#include "robot_manager_inheritance/base_robot_manager.h"
#include "robot_manager_inheritance/mobile_robot_manager.h"


int main(int argc, char  **argv)
{
    ros::init(argc, argv, "robot_manager");
    ros::NodeHandle nh;
    
    RobotManagerMobile robot(&nh,"/odom");
    // RobotManagerBase &rmb=robot;
    ros::spin();
    return 0;
}
