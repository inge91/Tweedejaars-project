cmake_minimum_required(VERSION 2.8)
project(MotionEngine)

find_package(qibuild)

include_directories("${PROJECT_SOURCE_DIR}/Kinematics")
add_subdirectory(Kinematics)

include_directories("${PROJECT_SOURCE_DIR}/Kinematics_SWIG")
add_subdirectory(Kinematics_SWIG)

include_directories("${PROJECT_SOURCE_DIR}/ComController")
add_subdirectory(ComController)

