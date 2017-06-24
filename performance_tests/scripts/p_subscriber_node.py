#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
from performance_tests.msg import SuperAwesome

def callback(data):
    #rospy.loginfo(rospy.get_caller_id() + 'I heard %s', data.time)
    #rospy.loginfo(data.time)
    begintime=data.time
    begintimef= float(begintime)

    endtime = "%s" % rospy.get_time() #time when message is received
    endtimef = float(endtime)
    rospy.loginfo('LATENCY %f', endtimef-begintimef) #(endtimef-begintimef) should be zero if the desired loop rate coincides with the real rate
                                       #as latency is calculated by using time when message is sent by publisher and time when message is received by subscriber

def listener():

    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber('chatter', SuperAwesome, callback)

    rospy.spin()

if __name__ == '__main__':
    listener()
