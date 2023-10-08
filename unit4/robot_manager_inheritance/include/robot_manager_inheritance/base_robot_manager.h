
// #ifdef BASE_ROBOT_MANAGER_H
#define BASE_ROBOT_MANAGER_H

#include "ros.h"
#include <std_srvs/SetBool.h>


class RobotManagerBase
{
private:
   bool output_enabled=false;
   ros::ServiceServer config_output_srv;
public:
    RobotManagerBase(/* args */);
    ~RobotManagerBase();
    void init_config_output_srv();
    bool ConfigOutputCallback(std_srvs::SetBoolRequest &req, std_srvs::SetBoolResponse &response);
};




// #endif