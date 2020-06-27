#include "ros/ros.h"
#include "std_msgs/Float64.h"

#include <string>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher joint1_pub = n.advertise<std_msgs::Float64>("/rrbot/joint1_torque/command", 1000);
  ros::Publisher joint2_pub = n.advertise<std_msgs::Float64>("/rrbot/joint2_torque/command", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    std_msgs::Float64 joint1_torque;
    std_msgs::Float64 joint2_torque;

    joint1_torque.data = std::stof(argv[1]);
    joint2_torque.data = std::stof(argv[2]);

    ROS_INFO("%f", joint1_torque.data);
    ROS_INFO("%f", joint2_torque.data);

    joint1_pub.publish(joint1_torque);
    joint2_pub.publish(joint2_torque);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
