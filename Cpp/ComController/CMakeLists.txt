cmake_minimum_required(VERSION 2.8)
project(ComController)

find_package(qibuild)

set(CMAKE_CXX_FLAGS "-std=c++0x")

# Create a executable named CenterOfMass
# with the source file: main.cpp
qi_create_bin(ComController p_controller.cpp)
qi_use_lib(ComController ALCOMMON kinematics eigen)
