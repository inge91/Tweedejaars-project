cmake_minimum_required(VERSION 2.8)
project(Kinematics)

find_package(qibuild)

add_definitions("-std=c++0x")

# Create a executable named Kinematics
# with the source file: main.cpp
qi_create_lib(kinematics kinematics.cpp)
qi_use_lib(kinematics ALCOMMON)

install (FILES kinematics.h DESTINATION ../include)
install (TARGETS kinematics DESTINATION ../lib )
