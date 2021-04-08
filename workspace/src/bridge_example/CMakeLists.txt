cmake_minimum_required(VERSION 2.8.3)
project(bridge_example)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
)

catkin_package(
  DEPENDS
    roscpp
    sensor_msgs
)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(lidar_print src/lidar_print.cc)
target_link_libraries(lidar_print
   ${catkin_LIBRARIES}
)

install(TARGETS lidar_print
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
