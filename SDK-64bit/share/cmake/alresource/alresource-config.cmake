# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(ALRESOURCE_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(ALRESOURCE_INCLUDE_DIRS)
   
set(ALRESOURCE_DEPENDS "ALCOMMON;ALTOOLS;ALSOAP;ALVALUE;TINYXML;RTTOOLS;RT;ALTHREAD;BOOST;BOOST_SIGNALS;BOOST_PROGRAM_OPTIONS;ALLOGREMOTE;ZEROMQ;UUID;PYTHON;ALCORE;QI;BOOST_FILESYSTEM;BOOST_THREAD;BOOST_DATE_TIME;PTHREAD;DL;ALERROR;ALCOMMON;ALTOOLS;ALSOAP;ALVALUE;TINYXML;RTTOOLS;RT;ALTHREAD;BOOST;BOOST_SIGNALS;BOOST_PROGRAM_OPTIONS;ALLOGREMOTE;ZEROMQ;UUID;PYTHON;ALCORE;QI;BOOST_FILESYSTEM;BOOST_THREAD;BOOST_DATE_TIME;PTHREAD;DL;ALERROR" CACHE STRING "" FORCE)
mark_as_advanced(ALRESOURCE_DEPENDS)

set(ALRESOURCE_DEFINITIONS "" CACHE STRING "" FORCE)
mark_as_advanced(ALRESOURCE_DEFINITIONS)
 

find_library(ALRESOURCE_DEBUG_LIBRARY alresource_d)
find_library(ALRESOURCE_LIBRARY       alresource)


if (ALRESOURCE_DEBUG_LIBRARY)
  set(ALRESOURCE_LIBRARIES optimized;${ALRESOURCE_LIBRARY};debug;${ALRESOURCE_DEBUG_LIBRARY})
else()
  set(ALRESOURCE_LIBRARIES ${ALRESOURCE_LIBRARY})
endif()
set(ALRESOURCE_LIBRARIES "${ALRESOURCE_LIBRARIES}" CACHE STRING "" FORCE)
mark_as_advanced(ALRESOURCE_LIBRARIES)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ALRESOURCE DEFAULT_MSG
  ALRESOURCE_LIBRARIES
  ALRESOURCE_INCLUDE_DIRS
)
# Right after find_package_handle_standard_args, _FOUND is
# set correctly.
# For instance, if foo/bar.h is not foud, FOO_FOUND is FALSE.
# But, right after this, since foo-config.cmake HAS been found, CMake
# re-set FOO_FOUND to TRUE.
# So we set _PACKAGE_FOUND in cache...
set(ALRESOURCE_PACKAGE_FOUND ${ALRESOURCE_FOUND} CACHE INTERNAL "" FORCE)
 