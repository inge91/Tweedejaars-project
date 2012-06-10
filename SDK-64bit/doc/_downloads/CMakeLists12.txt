cmake_minimum_required(VERSION 2.6.4 FATAL_ERROR)
project(arv2avi)
find_package(qibuild)

qi_create_bin(arv2avi arv2avi.cpp)
qi_use_lib(arv2avi ALVISION OPENCV BOOST_FILESYSTEM)
