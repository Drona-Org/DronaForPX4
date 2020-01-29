#include "../SoftwareStack/MailDeliveryTaskPlanner.h"
#include "RobotFuncs.h"
#include <math.h>
#include <unistd.h>
#include <cmath> 
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <ros/console.h>
#include <nav_msgs/Odometry.h>
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Quaternion.h"
#include "tf/transform_datatypes.h"
#include <tf/LinearMath/Matrix3x3.h>
#include "PlanGenerator.h"
#include "WorkspaceParser.h"
#include <cstring>
using namespace std;


geometry_msgs::Twist vel_msg;
ros::Publisher velocity_publisher;
ros::Subscriber gazebo_odom_subscriber;
float robot_x;
float robot_y;
float robot_theta;


WS_Coord shiftBy = WS_Coord(0, 0, 0);

WS_Coord GazeboToPlanner(WS_Coord coord) {
    return WS_Coord(coord.x + shiftBy.x, coord.y + shiftBy.y, coord.z + shiftBy.z);
}

WS_Coord PlannerToGazebo(WS_Coord coord) {
    return WS_Coord(coord.x - shiftBy.x, coord.y - shiftBy.y, coord.z - shiftBy.z);
}

double getDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2-x1), 2)+pow((y2-y1), 2));
}

void gazeboCallBack(const nav_msgs::Odometry::ConstPtr& odom_msg) {
    robot_x = odom_msg->pose.pose.position.x;
    robot_y = odom_msg->pose.pose.position.y;

    tf::Quaternion quat;
    tf::quaternionMsgToTF(odom_msg->pose.pose.orientation, quat);
    double roll, pitch, yaw;
    tf::Matrix3x3(quat).getRPY(roll, pitch, yaw);
    geometry_msgs::Vector3 rpy;
    rpy.x = roll;
    rpy.y = pitch;
    rpy.z = yaw;
    
    robot_theta = yaw;
}

void gazebo_move_goal(double goal_x, double goal_y) {
    geometry_msgs::Twist vel_msg;
    ros::Rate loop_rate(1000000);

    usleep(500000);
    ros::spinOnce();

    while (getDistance(goal_x, goal_y, robot_x, robot_y) >= 0.1) {
        double inc_x = goal_x - robot_x;
        double inc_y = goal_y - robot_y;
        double angle_to_goal = atan2(inc_y, inc_x);
        
        double tmp_linear_x = 0.2*getDistance(robot_x, robot_y, goal_x, goal_y);
        double tmp_angular_z = 1.0*std::abs((atan2(goal_y-robot_y, goal_x - robot_x)) - (robot_theta));
        
        if (tmp_linear_x < 0) {
            tmp_linear_x = max(-0.3, tmp_linear_x);
        } else {
            tmp_linear_x = min(0.3, tmp_linear_x);
        }
        
        if (tmp_angular_z < 0) {
            tmp_angular_z = max(-1.0, tmp_angular_z);
        } else {
            tmp_angular_z = min(1.0, tmp_angular_z);
        }

        vel_msg.linear.x = tmp_linear_x;
        vel_msg.linear.y = 0;
        vel_msg.linear.z = 0;
        vel_msg.angular.x = 0;
        vel_msg.angular.y = 0;
        vel_msg.angular.z = tmp_angular_z;

        velocity_publisher.publish(vel_msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    vel_msg.angular.x = 0;
    vel_msg.angular.z = 0;
    velocity_publisher.publish(vel_msg);
    ros::spinOnce();
    loop_rate.sleep();
    vel_msg.angular.z = 0;
    vel_msg.linear.x = 0;
    velocity_publisher.publish(vel_msg);
}

PRT_VALUE* P_OmplMotionPlanExternal_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE** P_VAR_destinations = argRefs[0];
    PRT_VALUE** P_VAR_robot_id = argRefs[1];
    int robot_id = PrtPrimGetInt(*P_VAR_robot_id);

    char robot_id_string[32];
    sprintf(robot_id_string, "%d", robot_id);
    
    char sub_beginning[512] = "robot";
    char sub_ending[128] = "/odom";
    strcat(sub_beginning, robot_id_string);
    strcat(sub_beginning, sub_ending);

    char sub_beginning2[512] = "robot";
    char sub_ending2[128] = "/cmd_vel";
    strcat(sub_beginning2, robot_id_string);
    strcat(sub_beginning2, sub_ending2);

    ros::NodeHandle n;
    gazebo_odom_subscriber = n.subscribe(sub_beginning, 1000000000, gazeboCallBack);
    velocity_publisher = n.advertise<geometry_msgs::Twist>(sub_beginning2, 1000000);

    double arrOfPoints[PrtSeqSizeOf(*P_VAR_destinations)][3];

    for (int i=0; i < (sizeof(arrOfPoints)/sizeof(*arrOfPoints)); i++) {
        double x = (*P_VAR_destinations)->valueUnion.seq->values[i]->valueUnion.tuple->values[0]->valueUnion.ft;
        double y = (*P_VAR_destinations)->valueUnion.seq->values[i]->valueUnion.tuple->values[1]->valueUnion.ft;
        double z = (*P_VAR_destinations)->valueUnion.seq->values[i]->valueUnion.tuple->values[2]->valueUnion.ft;
        arrOfPoints[i][0] = x;
        arrOfPoints[i][1] = y;
        arrOfPoints[i][2] = z;
    }

    vector<WS_Coord> destinations;
    for (int i=0; i < PrtSeqSizeOf(*P_VAR_destinations); i++){
        destinations.push_back(WS_Coord(arrOfPoints[i][0], arrOfPoints[i][1], arrOfPoints[i][2]));
    }
    
    OMPLPLanner* planner = new OMPLPLanner("/home/sumukh/catkin_ws/src/Drona/PSrc/SoftwareStack/Exp1.xml", PLANNER_RRTSTAR, OBJECTIVE_PATHLENGTH);
    double arrOfPoints2[destinations.size()*2-2][3];
    int j = 0;

    for(int i = 0; i< destinations.size()-1; i++)
    {
        WS_Coord gazToPlan = GazeboToPlanner(destinations.at(i));
        WS_Coord gazToPlan2 = GazeboToPlanner(destinations.at(i+1));
        vector<WS_Coord> path = planner->GeneratePlan(1, GazeboToPlanner(destinations.at(i)), GazeboToPlanner(destinations.at(i+1)));
        vector<WS_Coord> pathNew = path;

        for (int count = 0; count < pathNew.size(); count++)
        {
            WS_Coord shifted = PlannerToGazebo(pathNew.at(count));
            cout << shifted.ToString() << endl;
            double x = shifted.x;
            double y = shifted.y;
            double z = shifted.z;
            printf("%f %f %f\n",x,y,z);
            arrOfPoints2[j][0] = x;
            arrOfPoints2[j][1] = y;
            arrOfPoints2[j][2] = z;
            j++;
        }
    }
    
    PRT_VALUE* mainPRT = (PRT_VALUE*)PrtMalloc(sizeof(PRT_VALUE));
	mainPRT->discriminator = (PRT_VALUE_KIND)2;
    PRT_SEQVALUE* motionplan = (PRT_SEQVALUE*)PrtMalloc(sizeof(PRT_SEQVALUE));
	mainPRT->valueUnion.seq = motionplan;

	motionplan->size = j;
	motionplan->capacity = (PRT_UINT32)100;
	PRT_VALUE** tupArray = (PRT_VALUE**)PrtMalloc(sizeof(PRT_VALUE*) * motionplan->size);
	motionplan->values = tupArray;

	for (int i = 0; i < motionplan->size; i++) {
		*(tupArray+i) = (PRT_VALUE*)PrtMalloc(sizeof(PRT_VALUE));
		(*(tupArray+i))->discriminator = PRT_VALUE_KIND_TUPLE;
		PRT_TUPVALUE* tuple = (PRT_TUPVALUE*)PrtMalloc(sizeof(PRT_TUPVALUE));
		(*(tupArray+i))->valueUnion.tuple = tuple;

		tuple->size = 3;
		PRT_VALUE** floatArray = (PRT_VALUE**)PrtMalloc(sizeof(PRT_VALUE*) * 3);
		tuple->values = floatArray;

		for (int j = 0; j < 3; j++) {
			*(floatArray+j) = (PRT_VALUE*)PrtMalloc(sizeof(PRT_VALUE));
			(*(floatArray+j))->discriminator = PRT_VALUE_KIND_FLOAT;
			(*(floatArray+j))->valueUnion.ft = arrOfPoints2[i][j];
		}
	}
    gazebo_odom_subscriber.shutdown();
    return mainPRT;
}

PRT_VALUE* P_ROSGoTo_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    struct PRT_VALUE* mainPRT = *(argRefs[0]);
    PRT_VALUE** P_VAR_robot_id = argRefs[1];
    int robot_id = PrtPrimGetInt(*P_VAR_robot_id);

    char robot_id_string[32];
    sprintf(robot_id_string, "%d", robot_id);
    
    char sub_beginning[512] = "robot";
    char sub_ending[128] = "/odom";
    strcat(sub_beginning, robot_id_string);
    strcat(sub_beginning, sub_ending);

    char sub_beginning2[512] = "robot";
    char sub_ending2[128] = "/cmd_vel";
    strcat(sub_beginning2, robot_id_string);
    strcat(sub_beginning2, sub_ending2);

    ros::NodeHandle n;
    gazebo_odom_subscriber = n.subscribe(sub_beginning, 1000000000, gazeboCallBack);
    velocity_publisher = n.advertise<geometry_msgs::Twist>(sub_beginning2, 1000000);

	double destinationPoints[mainPRT->valueUnion.seq->size][3];
	
	for (int i = 0; i < mainPRT->valueUnion.seq->size; i++) {
		double x = mainPRT->valueUnion.seq->values[i]->valueUnion.tuple->values[0]->valueUnion.ft;
        double y = mainPRT->valueUnion.seq->values[i]->valueUnion.tuple->values[1]->valueUnion.ft;
        double z = mainPRT->valueUnion.seq->values[i]->valueUnion.tuple->values[2]->valueUnion.ft;
		destinationPoints[i][0] = x;
        destinationPoints[i][1] = y;
        destinationPoints[i][2] = z;
        
		printf("%f, %f, %f\n", x,y,z);
        gazebo_move_goal(x, y);
	}
    gazebo_odom_subscriber.shutdown();
    return PrtMkIntValue((PRT_UINT32)1);
}

PRT_VALUE* P_Sleep_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
	PRT_VALUE** P_VAR_time = argRefs[0];
	float secs = PrtPrimGetFloat(*P_VAR_time);
	usleep(secs*1000000);
    return PrtMkIntValue((PRT_UINT32)1);
}