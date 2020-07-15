cmake_minimum_required(VERSION 2.8.3)
project(eigen_use)

find_package(Eigen3 REQUIRED)

add_executable(eigen_use eigen_use.cpp)