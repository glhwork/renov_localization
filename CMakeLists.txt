cmake_minimum_required(VERSION 2.8.3)
project(renov_localization)

find_package(catkin REQUIRED
  roscpp
  rospy
  std_msgs
)

include_directories(include)

add_executable(${PROJECT_NAME}_kalman_filter src/kalman_filter.cpp)
