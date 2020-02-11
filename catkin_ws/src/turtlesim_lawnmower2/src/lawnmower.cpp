#include "/opt/ros/kinetic/include/ros/ros.h"
#include "/opt/ros/kinetic/include/geometry_msgs/Twist.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << endl;

    ros::init(argc, argv, "lawnmower");
    ros::NodeHandle n;

    ros::Publisher turtle_vel = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    ros::Rate loop_rate(10);

    geometry_msgs::Twist msg;
    msg.linear.x = 1;

    while (ros::ok()) {
        turtle_vel.publish(msg);

        loop_rate.sleep();
    }
    return 0;
}
