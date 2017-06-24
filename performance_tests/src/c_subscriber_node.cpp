#include "ros/ros.h"
#include "performance_tests/SuperAwesome.h"
#include <iostream>
#include <sstream>
#include <math.h>

double begintime;
double endtime;

void chatterCallback(const performance_tests::SuperAwesome::ConstPtr& msg)
{
  //ROS_INFO("%s", msg->time.c_str());
  endtime = ros::Time::now().toSec(); //time when message is received
  endtime=round(endtime*100)/100;
  begintime=atof(msg->time.c_str());
  begintime=round(begintime*100)/100;
  ROS_INFO("LATENCY %f",(endtime-begintime)); //(endtime-begintime) should be zero if the desired rate coincides with the real rate
                                      //as the latency is calculated by using time when message is sent from publisher and time when message is received by subscriber

}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "c_subscriber_node");

  ros::NodeHandle n;
  ros::Subscriber sub=n.subscribe("chatter", 10, chatterCallback);
 // ss.s>>endtime;

  ros::spin();

  return 0;
}
