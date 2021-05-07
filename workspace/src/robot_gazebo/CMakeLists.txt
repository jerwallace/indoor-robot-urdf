cmake_minimum_required(VERSION 3.5.1)
project(robot_gazebo)

# c++11 if using kinetic
add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  gazebo_ros
)

find_package(gazebo REQUIRED)

catkin_package(
  DEPENDS
    roscpp
    gazebo_ros
)

link_directories(${GAZEBO_LIBRARY_DIRS} ${catkin_LIBRARY_DIRS})
include_directories(include ${Boost_INCLUDE_DIR} ${catkin_INCLUDE_DIRS} ${GAZEBO_INCLUDE_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(hello_world SHARED src/hello_world.cc)
target_link_libraries(hello_world ${GAZEBO_LIBRARIES})

install(DIRECTORY include/
   DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}
   FILES_MATCHING PATTERN "*.h"
)

install(DIRECTORY launch world
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(TARGETS hello_world
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)