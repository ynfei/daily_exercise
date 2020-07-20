cmake_minimum_required(VERSION 2.8.3)
project(videobag)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  rosbag
  roscpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

find_package(OpenCV REQUIRED )

include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(videobag src/main.cpp)

target_link_libraries(videobag
   ${catkin_LIBRARIES} ${OpenCV_LIBS}
    )

