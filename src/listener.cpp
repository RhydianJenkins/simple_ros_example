/**
**  Simple ROS Listener Node
**/
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

void callbackFunction(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("Listener node heared [%s] on chatter topic.", msg->data.c_str());
}


int main(int argc, char **argv) {
    // This must be called before anything else ROS-related
    ros::init(argc, argv, "listener");

    // Create a ROS node handle
    ros::NodeHandle nh;

    // Create the subscriber object
    // (TOPIC TO SUB TO, REFRESH RATE, CALLBACK FUNCTION WHEN HEARED)
    ros::Subscriber sub = nh.subscribe("chatter", 1000, callbackFunction);

    // 'spin' will enter a loop, pumping callbacks.
    ros::spin();

    // Simple exit statement
    return 0;
}