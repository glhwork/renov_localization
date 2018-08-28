cmake_minimum_required(VERSION 2.8.3)
project(renov_localization)

add_compile_options(-std=c++11)

set(Eigen3_DIRS /usr/lib/cmake/eigen3)
find_package(catkin REQUIRED
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_generation
)

find_package(Eigen3 REQUIRED)

add_message_files (
  FILES
  uwb_info.msg
)

generate_messages (
  DEPENDENCIES
  std_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp rospy std_msgs geometry_msgs message_runtime
)

add_library(test_lib
  src/Trilateration.cpp
)

target_link_libraries(test_lib
  ${catkin_LIBRARIES}
)


add_executable(${PROJECT_NAME}_main src/main.cpp)
add_executable(${PROJECT_NAME}_trila_test 
  src/trila_test.cpp
  src/Trilateration.cpp
)
target_link_libraries(${PROJECT_NAME}_trila_test
  test_lib
  ${catkin_LIBRARIES}
)
