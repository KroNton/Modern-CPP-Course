#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "../../velocity_library/include/velocity_library.h"


void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  
  float linear_vel = msg->twist.twist.linear.x;
  float angular_vel = msg->twist.twist.angular.z;
  display_vel(linear_vel,angular_vel);
  
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "odom_vel_listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("odom", 1000, odomCallback);
  
  ros::spin();

  return 0;
}