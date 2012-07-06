cmake_minimum_required(VERSION 2.8)
project(CenterOfMass)

find_package(qibuild)
find_package(boost COMPONENTS numeric REQUIRED)

set(CMAKE_CXX_FLAGS "-std=c++0x")

# Create a executable named CenterOfMass
# with the source file: main.cpp
qi_create_bin(CenterOfMass com.cpp p_controller.cpp)
qi_use_lib(CenterOfMass ALCOMMON)
