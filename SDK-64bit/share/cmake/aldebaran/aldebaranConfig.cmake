##
## Copyright (C) 2011 Aldebaran Robotics
##

##
# This file contains specific Aldebaran
# settings for every 'desktop' projects:


# We you use CDash, for your tests, you use:
#   include(CTest)
# and this handles the call to enable_testing()
#
# We do not use CDash, so we can safely always call this:
enable_testing()

# We need this for boost 1.44 to use boost::filesystem v3 API
# (the v3 version is on by default in later versions of boost)
add_definitions("-DBOOST_FILESYSTEM_VERSION=3")

if(MSVC)
  # If your using Visual Studio Express and this setting is on, you
  # will get a annoying pop-up and visual studio will convert the project
  # to remove the subfolders, so let's not use this by default.
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  if(MSVC10)
    # Avoid GTEST using its own tuple, when we have a real tuple
    add_definitions(" -DGTEST_USE_OWN_TR1_TUPLE=0 ")
  endif()
  # Fix annoying windows.h quirks:
  add_definitions(" -DNOMINMAX ")
  add_definitions(" -D_CRT_SECURE_NO_DEPRECATE ")

  # Specific to Aldebaran:
  # This reduces the build time when you
  # include Windows.h, but you have to include winsock2.h
  # yourself.
  add_definitions(" -DWIN32_LEAN_AND_MEAN ")
endif()
