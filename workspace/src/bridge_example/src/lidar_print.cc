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

int main(int argc,char**argv) {
    
    ros::init(argc,argv,"laser_scan_print");
    
    ros::start();
    
    ros::NodeHandle n;
    
    ros::Subscriber sub = n.subscribe("/lidar_scan", 1000, laserCallback);
    
    ros::spin();
    
    ros::shutdown();

    return 0;
}
