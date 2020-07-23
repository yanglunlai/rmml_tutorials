#include <ros/ros.h>
#include <iostream>
#include <cmath>
#include <sensor_msgs/LaserScan.h>
#include <time.h>
#include "std_msgs/String.h"

#define RAD2DEG(x) ((x)*180./M_PI)
using namespace std;

double d;

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
    d= msg->ranges[0];
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "s");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 2000, scanCallback);
    ros::Publisher  pub = n.advertise<std_msgs::String>("distance_cpp", 1000);
    ros::Rate loop_rate(10);
    
    while(ros::ok())
{
    std_msgs::String msg;
    std::ostringstream ss;
    ss << d;
    msg.data = ss.str();
    //ROS_INFO("%s", msg.data.c_str());
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
}
    return 0;
}
