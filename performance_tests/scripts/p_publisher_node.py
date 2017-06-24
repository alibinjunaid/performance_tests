#!/usr/bin/env python
# license removed for brevity
import rospy
from performance_tests.msg import SuperAwesome

def talker():
    pub = rospy.Publisher('chatter', SuperAwesome, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    #rate = rospy.Rate(100000)
    looprate=1000 # initial looprate
    looprateflag=0
    while not rospy.is_shutdown():
        rate = rospy.Rate(looprate) # 10hz
        begin_str = "%s" % rospy.get_time() #time when message is sent
        rospy.loginfo('DESIRED_LOOP_RATE_HZ %d',looprate)
        pub.publish(begin_str)
        looprateflag += 1
        if looprateflag == 100:
            looprate = looprate + 100
            looprateflag = 0
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
