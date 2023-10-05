#include "my_robot_manager/robot_manager.h"
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <string>
//initialize robot_count static class member
int RobotManager::robot_count=0;

//parmeterized constructor
RobotManager::RobotManager(ros::NodeHandle *nh,std::string robot_name,std::string cmd_vel_topic,std::string odometry_topic){
    odometry_topic=this->odometry_topic;
    robot_name= this->robot_name;
    cmd_vel_topic=this->cmd_vel_topic;

    odom_subscriber= nh->subscribe(odometry_topic,50,&RobotManager::odom_callback,this);
    cmd_vel_publisher=nh->advertise<geometry_msgs::Twist>(cmd_vel_topic, 10);
    robot_count++;
    ROS_INFO("Robot %d created", robot_count);
   
}

// Copy constructor
RobotManager::RobotManager(const RobotManager &copy_obj){
  current_x_position=copy_obj.current_x_position;
  current_y_position=copy_obj.current_y_position;
}

//use the default version of the destructor to the class.
RobotManager::~RobotManager()=default;

void RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &odom_msg){
   
   current_x_position= odom_msg->pose.pose.position.x;
   current_y_position= odom_msg->pose.pose.position.y;
    
}


std::string RobotManager::get_robot_name(){
    return robot_name;
}


void RobotManager::move_forward(int seconds){
  ros::Rate loop_rate(10);
  ros::Time start_time = ros::Time::now();
  ros::Duration timeout(seconds);
  
  while ((ros::Time::now() - start_time)<timeout)
  {
    ros::spinOnce();
    vel_msg.linear.x=0.4;
    cmd_vel_publisher.publish(vel_msg);
    loop_rate.sleep();
  }
  vel_msg.linear.x=0.0;
  vel_msg.angular.z = 0.0;
  cmd_vel_publisher.publish(vel_msg);

}


void RobotManager::move_backward(int seconds){
  ros::Rate loop_rate(10);
  ros::Time start_time = ros::Time::now();
  ros::Duration timeout(seconds);
  while ((ros::Time::now() - start_time)<timeout)
  {
    ros::spinOnce();
    vel_msg.linear.x=-0.4;
    cmd_vel_publisher.publish(vel_msg);
    loop_rate.sleep();
  }
  vel_msg.linear.x=0.0;
  vel_msg.angular.z = 0.0;
  cmd_vel_publisher.publish(vel_msg);

}



void RobotManager::turn(std::string clock, int n_secs){
  float CW;
  if (clock=="cw")
  {
   CW=-0.6;
   std::cout<<"Turnning clock wise"<<std::endl;
  }
  else if(clock=="ccw"){
    CW=0.6;
     std::cout<<"Turnning counter clock wise"<<std::endl;
  }
  else{
    std::cout<<"wrong value... you can choose between:\n (1)cw \n (2)ccw"<<std::endl;
  }

  ros::Rate loop_rate(10);
  ros::Time start_time = ros::Time::now();
  ros::Duration timeout(n_secs);
  while ((ros::Time::now() - start_time)<timeout)
  {
    ros::spinOnce();
    vel_msg.angular.z = CW;
    cmd_vel_publisher.publish(vel_msg);
    loop_rate.sleep();
  }
  vel_msg.linear.x=0.0;
  vel_msg.angular.z = 0.0;
  cmd_vel_publisher.publish(vel_msg);

}
  


float RobotManager::get_coords(int param){

  if (param == 1) {
    return this->current_x_position;
  } else if (param == 2) {
    return this->current_y_position;
  } 
  return 0;
}