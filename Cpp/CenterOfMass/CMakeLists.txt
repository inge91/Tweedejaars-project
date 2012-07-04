cmake_minimum_required(VERSION 2.8)
project(CenterOfMass)

find_package(qibuild)
find_package(boost COMPONENTS numeric tuple REQUIRED)

# Create a executable named CenterOfMass
# with the source file: main.cpp
qi_create_lib(CenterOfMass "com.cpp")
qi_use_lib(CenterOfMass ALCOMMON)

# Add a simple test:
enable_testing()
qi_create_test(test_CenterOfMass "test.cpp")
