cmake_minimum_required(VERSION 2.8)
project(Kinematics_SWIG)

find_package(qibuild)

add_definitions("-std=c++11")

include(qibuild/swig/python)
qi_swig_wrap_python(kinematics_swig kinematics_swig.i
  SRC "kinematics_swig.cpp"
  DEPENDS ALCOMMON eigen kinematics)
