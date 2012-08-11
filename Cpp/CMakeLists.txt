cmake_minimum_required(VERSION 2.8)
project(MotionEngine)

find_package(qibuild)

include_directories("${PROJECT_SOURCE_DIR}/Kinematics")
add_subdirectory(Kinematics)
