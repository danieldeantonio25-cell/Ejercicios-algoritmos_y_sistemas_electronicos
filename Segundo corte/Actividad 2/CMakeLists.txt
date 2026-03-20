cmake_minimum_required(VERSION 3.10)
project(Actividad2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Asegúrate de que cada línea de add_executable esté bien cerrada
add_executable(twitter 355_Design_Twitterr.cpp)
add_executable(spreadsheet 3484_Design-spreadsheett.cpp)
add_executable(queen_attack queen-attack.cpp)
add_executable(robot_simulator robot-simulator.cpp)

