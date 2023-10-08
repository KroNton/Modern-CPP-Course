#include "robot_manager_inheritance/base_robot_manager.h"

void RobotManagerBase::init_config_output_srv(ros::NodeHandle *nh){
    config_output_srv = nh->advertiseService("robot_manager_output", &RobotManagerBase::ConfigOutputCallback, this);
    
}

bool RobotManagerBase::ConfigOutputCallback(
    std_srvs::SetBoolRequest &req, std_srvs::SetBoolResponse &response) {
        
  bool request = req.data;

  // Check if request is same as current output configuration
  if (request == output_enabled) {
    response.success = false;
    response.message = "Output configuration request is the same as the "
                       "current output configuration.";
    return true;
  }

  response.success = true;
  output_enabled = request;
  if (output_enabled == false) {
    response.message = "Console output disabled.";
    ROS_INFO("Robot Manager console output disabled.");
  } else {
    response.message = "Console output enabled.";
    ROS_INFO("Robot Manager console output enabled.");
  }
  return true;
}

RobotManagerMobile::RobotManagerMobile(ros::NodeHandle *nh,std::string odom_topic){
odometry_topic=odom_topic;
init_config_output_srv(nh);
init_odom_subscriber(nh);
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