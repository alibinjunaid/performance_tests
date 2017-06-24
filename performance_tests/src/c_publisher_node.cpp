#include "ros/ros.h"
#include "performance_tests/SuperAwesome.h"
#include <sstream>

int looprate=1000; //initial looprate
int looprateflag=0;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "c_publisher_node");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<performance_tests::SuperAwesome>("chatter", 1000);

  while (ros::ok())
  {
    ros::Rate loop_rate(looprate);

    performance_tests::SuperAwesome msg;
    std::stringstream ss;

    ros::Time begin = ros::Time::now(); //time when message is sent
    ss << begin;
    msg.time = ss.str();
    ROS_INFO("DESIRED_LOOP_RATE_HZ %d", looprate);
    chatter_pub.publish(msg);

    ros::spinOnce();

    looprateflag++;
    if(looprateflag==100)
    {
      looprate=looprate+10;
      looprateflag=0;
    }

    loop_rate.sleep();

  }
  return 0;
}
