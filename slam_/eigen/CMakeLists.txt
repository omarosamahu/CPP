cmake_minimum_required(VERSION 3.5)

project(eigen VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3 REQUIRED)

add_executable(trans src/transformation.cpp)

include_directories(${EIGEN3_INCLUDE_DIR}) 




# find_package(OpenMVG REQUIRED)
# find_package(Ceres REQUIRED)



# include_directories(${CERES_INCLUDE_DIRS}) 
# target_link_libraries(trans 
#                      -DEigen3
#                      ${CERES_LIBRARIES})
