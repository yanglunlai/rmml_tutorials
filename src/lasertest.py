#! /usr/bin/env python
import rospy
import time
from sensor_msgs.msg import LaserScan
from std_msgs.msg import Float32
 
def scanCallback(msg):
    d=msg.ranges[180]
    pub.publish(d)
    rate = rospy.Rate(1) 
    rate.sleep()

rospy.init_node('scan_values_python')
sub = rospy.Subscriber('/scan', LaserScan, scanCallback)
pub = rospy.Publisher('/distance_python', Float32 ,queue_size=1)
rospy.spin()

