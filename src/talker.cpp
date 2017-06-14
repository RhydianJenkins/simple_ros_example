/**
**  Simple ROS Talker Node
**/
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv) {
    // This must be called before anything else ROS-related
    ros::init(argc, argv, "talker");

    // Create a ROS node handle
    ros::NodeHandle nh;

    // Create the publisher object
    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 1000);

    // How often to publish
    ros::Rate loop_rate(10);

    // The main loop
    while (ros::ok()) {
        // The message object that will be published
        std_msgs::String msg;

        // Stuff the message object with data
        std::stringstream ss;
        ss << "Hello World!";
        msg.data = ss.str();

        // Publish the message
        pub.publish(msg);

        // Print out that we said Hello World!
        ROS_INFO("Publishing 'Hello World!' message to chatter topic.");

        // Call all the callbacks waiting to be called at that point in time (execute)
        ros::spinOnce();

        // Sleep for specified time in order to achieve desired publish loop rate
        loop_rate.sleep();
    }

}