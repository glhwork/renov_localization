cmake_minimum_required(VERSION 2.8.3)
project(renov_localization)

find_package(catkin REQUIRED
  roscpp
  rospy
  std_msgs
  Eigen
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)


add_executable(${PROJECT_NAME}_main src/main.cpp)
add_executable(${PROJECT_NAME}_trila_main src/trila_main.cpp)
