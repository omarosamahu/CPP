cmake_minimum_required(VERSION 3.5.1)

project(SLAM_Kimera)

set (CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)


add_executable(foo foo.cpp)
target_link_libraries(foo PUBLIC ${OpenCV_LIBS})


