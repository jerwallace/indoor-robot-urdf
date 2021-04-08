// Include the ROS C++ APIs
#include <ros/ros.h>
#include "sensor_msgs/LaserScan.h"

void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
    for(int i=0;i<(msg->ranges.size());i++){
        //_lsval.ranges[i]=msg->ranges[i];
        if(!(msg->ranges.empty())) {
            ROS_INFO("data %f",msg->ranges[i]);
        } else {
            ROS_INFO("NO VALUE");
        }
    }
}

// Standard C++ entry point
int main(int argc,char**argv) {
    
    // Announce this program to the ROS master as a "node" called "hello_world_node"
    ros::init(argc,argv,"laser_scan_print");
    
    // Start the node resource managers (communication, time, etc)
    ros::start();
    
    ros::NodeHandle n;
    
    ros::Subscriber sub = n.subscribe("laser_scan", 1000, laserCallback);
    
    // Process ROS callbacks until receiving a SIGINT (ctrl-c)
    ros::spin();
    
    // Stop the node's resources
    ros::shutdown();
    // Exit tranquilly

    return 0;
}