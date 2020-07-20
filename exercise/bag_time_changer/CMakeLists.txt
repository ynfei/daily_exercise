cmake_minimum_required(VERSION 2.8.3)
project(timestamp_changer)

find_package(catkin REQUIRED COMPONENTS
  sensor_msgs
  pcl_conversions
  cv_bridge
)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

find_package(PCL REQUIRED)
include_directories(PCL_INCLUDE_DIRS)

find_package(OpenCV REQUIRED)
include_directories(OpenCV_INCLUDE_DIRS)

add_executable(timestamp_changer bag_time_changer.cpp)
target_link_libraries(timestamp_changer ${catkin_LIBRARIES} ${OpenCV_LIBS} ${PCL_LIBRARIES})