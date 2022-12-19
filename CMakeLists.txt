cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
project(robot_navigation)

include_directories(include)

add_library(${PROJECT_NAME}  
    src/maze.cpp
    src/pos.cpp
    src/robot.cpp
    src/random_robot.cpp
    src/right_hand_rule_robot.cpp)

add_library(big_int
    src/big_int.cpp)

add_executable(main src/main.cpp)

target_link_libraries(main ${PROJECT_NAME})
