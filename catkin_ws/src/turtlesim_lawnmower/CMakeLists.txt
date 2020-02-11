cmake_minimum_required(VERSION 2.8.3)
project(simple_arm)

SET(BASEPATH "${CMAKE_SOURCE_DIR}")
INCLUDE_DIRECTORIES("/opt/ros/kinetic/include")
#INCLUDE_DIRECTORIES(include ${catkin_INCLUDE_DIRS})

message("catkin_DIRS=" ${catkin_INCLUDE_DIRS})

## Add support for C++11, supported in ROS Kinetic and newer
add_definitions(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
        std_msgs
        message_generation
        controller_manager
)

add_executable(turtlesim_lawnmower src/lawnmower.cpp)
target_link_libraries(turtlesim_lawnmower ${catkin_LIBRARIES})
#add_dependencies(simple_mover simple_arm_generate_messages_cpp)

