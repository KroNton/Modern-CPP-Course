#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <string>


class RobotManager {

private:
    float current_x_position;
    float current_y_position;
    std::string odometry_topic="/robot1/odom";
    std::string robot_name;
    ros::Subscriber odom_subscriber;

public:
    RobotManager(ros::NodeHandle *nh,std::string name,std::string odom_topic);
    void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);


};
