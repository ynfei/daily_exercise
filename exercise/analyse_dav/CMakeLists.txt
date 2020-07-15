cmake_minimum_required(VERSION 2.8.3)
project(dav_analyser)

find_package(OpenCV REQUIRED)

include_directories(
  OpenCV_INCLUDE_DIRS
)

add_executable(dav_analyser src/analyse_dav.cpp)
target_link_libraries(dav_analyser ${OpenCV_LIBS})