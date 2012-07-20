cmake_minimum_required(VERSION 2.8)
project(Kinematics)

find_package(qibuild)
find_package(boost COMPONENTS numeric REQUIRED)

# Create a executable named Kinematics
# with the source file: main.cpp
qi_create_lib(kinematics kinematics.cpp)
qi_use_lib(kinematics ALCOMMON)
