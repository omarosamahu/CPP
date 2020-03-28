cmake_minimum_required(VERSION 3.17.0-rc2)

project(kimera_project)

SET(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED COMPONENTS filesystem serialization regex timer date_time thread)
find_package(kimera_vio REQUIRED)


add_executable(out_kimera src/kimera.cpp 
                        src/kimera_plugin.cpp
                        )

target_link_libraries(out_kimera
                        PRIVATE
                        kimera_vio                        
)

target_compile_options(out_kimera
  PRIVATE -Wall -pipe
  PRIVATE -march=native
)
