#include "/opt/ros/kinetic/include/ros/ros.h"
#include "/opt/ros/kinetic/include/geometry_msgs/Twist.h"
//#include "std_msgs/Float64.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << "hello" << endl;
    cout << endl;

    // Initialize the arm_mover node
    ros::init(argc, argv, "lawnmower");
    // Create a handle to the arm_mover node
    ros::NodeHandle n;

    // Create a publisher that can publish a std_msgs::Float64 message on the /simple_arm/joint_1_position_controller/command topic
    ros::Publisher turtle_vel = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    // Set loop frequency of 10Hz
    ros::Rate loop_rate(50);

//    while(1)
//    {
//        ROS_INFO_STREAM("This is my index: ");
//    }


    geometry_msgs::Twist msg;

    double tstart, tstop;
    tstart = ros::Time::now().toSec();

    while (ros::ok()) 
    {
        tstop = ros::Time::now().toSec() - tstart;
        cout << tstop << endl;
        
        // Scaling down problem to 2m, 1m, 2m ... due to restricted size of turtlebot area

        // straight 2m
        if(tstop>0 && tstop<2)
        {
            msg.linear.x = 1;
        }

        // turn and straight 1m
	else if(tstop>=2 && tstop<3)
        {
            msg.linear.x = 1;
            msg.angular.z = 3.1415/2;
        }
	else if(tstop>=3 && tstop<3.5)
        {
            msg.linear.x = 1;
            msg.angular.z = 0;
        }
 	else if(tstop>=3.5 && tstop<4.5)
        {
            msg.linear.x = 1;
            msg.angular.z = 3.1415/2;
        }

        // straight 2m
	else if(tstop>=4.5 && tstop<6.5)
        {
            msg.linear.x = 1;
            msg.angular.z = 0;
        }

        // turn and straight 1m
	else if(tstop>=6.5 && tstop<7.5)
        {
            msg.linear.x = 1;
            msg.angular.z = -3.1415/2;
        }
	else if(tstop>=7.5 && tstop<8)
        {
            msg.linear.x = 1;
            msg.angular.z = 0;
        }
 	else if(tstop>=8 && tstop<9)
        {
            msg.linear.x = 1;
            msg.angular.z = -3.1415/2;
        }

        // straight 2m
	else if(tstop>=9 && tstop<11)
        {
            msg.linear.x = 1;
            msg.angular.z = 0;

        }

        //stop
	else if(tstop>=11)
        {
            msg.linear.x = 0;
            msg.angular.z = 0;
        }

        turtle_vel.publish(msg);

        // Sleep for the time remaining until 10 Hz is reached
        loop_rate.sleep();
    }
    return 0;
}
