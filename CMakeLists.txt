cmake_minimum_required(VERSION 2.8.3)
project(renov_localization)

set(Eigen3_DIRS /usr/lib/cmake/eigen3)
find_package(catkin REQUIRED
  roscpp
  rospy
  std_msgs
)

find_package(Eigen3 REQUIRED)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
)

add_library(test_lib
  src/Trilateration.cpp
)


add_executable(${PROJECT_NAME}_main src/main.cpp)
add_executable(${PROJECT_NAME}_trila_test 
  src/trila_test.cpp
  src/Trilateration.cpp
)
