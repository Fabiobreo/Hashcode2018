cmake_minimum_required(VERSION 3.9)
project(Hashcode)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

add_library(parser include/parser.hpp src/parser.cpp)
add_library(serializer include/serializer.hpp src/serializer.cpp)
add_library(log include/log.hpp src/log.cpp)
add_library(ride include/ride.hpp src/ride.cpp)

add_library(vehicle include/vehicle.hpp src/vehicle.cpp)
target_link_libraries(vehicle ride)

add_executable(hashcode src/main.cpp)
target_link_libraries(hashcode parser serializer log ride vehicle)