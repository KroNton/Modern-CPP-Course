#include "robot_manager_inheritance/base_robot_manager.h"
#include "robot_manager_inheritance/mobile_robot_manager.h"

RobotManagerMobile::RobotManagerMobile(ros::NodeHandle *nh,std::string odom_topic)
:odometry_topic(odom_topic)
{

init_config_output_srv(nh);
init_odom_subscriber(nh);
}
void RobotManagerMobile::displayRobotDetails(){
 std::cout<< "Robot Name: "<< robot_name<< "\n"<<"Robot Location: "<<robot_location<<std::endl;
 std::cout<< "Battery Charge Level: "<< battery_charge_level<< "\n"<<"Type of Battery: "<<type_of_battery<<std::endl;
}

void RobotManagerMobile::init_odom_subscriber(ros::NodeHandle *nh){

odom_subscriber = nh->subscribe(odometry_topic, 1000, &RobotManagerMobile::odom_callback, this);
 ROS_INFO("Odometry subscriber created");
}


void RobotManagerMobile::odom_callback(const nav_msgs::Odometry::ConstPtr &msg){
 if (output_enabled) {
  current_x_position= msg->pose.pose.position.x;
  current_y_position= msg->pose.pose.position.y;
  ROS_INFO("Position (x,y): %lf , %lf", current_x_position,current_y_position);
 }
}