cmake_minimum_required(VERSION 3.23)
project(untitled3)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled3 src/main.cpp src/Train.cpp src/PassengerTrain.cpp src/CargoTrain.cpp src/Entry.cpp src/DateAndTime.cpp include/DateAndTime.h)
target_include_directories(untitled3 PUBLIC include)