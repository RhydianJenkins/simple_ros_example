/**
**  Simple ROS Node
**/
#include <ros/ros.h>

int main(int argc, char* argv[]) {
    // This must be called before anything else ROS-related
    ros::init(argc, argv, "first_node");

    // Create a ROS node handle
    ros::NodeHandle nh;

    // Print to console
    ROS_INFO("Hello, World!");

    // Don't exit the program.
    ros::spin();
}