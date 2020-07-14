cmake_minimum_required(VERSION 2.8.3)
project(img_renamer)

set(CMAKE_BUILD_TYPE Release)

find_package(OpenCV REQUIRED)

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

add_executable(img_renamer src/ex1.cpp)
target_link_libraries(img_renamer ${OpenCV_LIBS})
