cmake_minimum_required(VERSION 3.15)

file(GLOB my_src ./src/*.cpp)

set(CMAKE_CXX_FLAGS "-std=c++17 -O3")

project(ivip CXX)

add_executable(ivip ${my_src})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(ivip ${OpenCV_LIBS})
