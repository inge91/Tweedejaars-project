# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(ALVISION_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(ALVISION_INCLUDE_DIRS)
   
set(ALVISION_DEPENDS "ALCOMMON;OPENCV;ALEXTRACTOR;ALSOAP;ALVALUE;TINYXML;RTTOOLS;RT;ALTHREAD;ALERROR;BOOST;BOOST_SIGNALS;BOOST_PROGRAM_OPTIONS;ALLOGREMOTE;QI;BOOST_FILESYSTEM;BOOST_THREAD;BOOST_DATE_TIME;PTHREAD;DL;ZEROMQ;UUID;PYTHON;ALCOMMON;OPENCV;ALEXTRACTOR;ALSOAP;ALVALUE;TINYXML;RTTOOLS;RT;ALTHREAD;ALERROR;BOOST;BOOST_SIGNALS;BOOST_PROGRAM_OPTIONS;ALLOGREMOTE;QI;BOOST_FILESYSTEM;BOOST_THREAD;BOOST_DATE_TIME;PTHREAD;DL;ZEROMQ;UUID;PYTHON" CACHE STRING "" FORCE)
mark_as_advanced(ALVISION_DEPENDS)

set(ALVISION_DEFINITIONS "" CACHE STRING "" FORCE)
mark_as_advanced(ALVISION_DEFINITIONS)
 

find_library(ALVISION_DEBUG_LIBRARY alvision_d)
find_library(ALVISION_LIBRARY       alvision)


if (ALVISION_DEBUG_LIBRARY)
  set(ALVISION_LIBRARIES optimized;${ALVISION_LIBRARY};debug;${ALVISION_DEBUG_LIBRARY})
else()
  set(ALVISION_LIBRARIES ${ALVISION_LIBRARY})
endif()
set(ALVISION_LIBRARIES "${ALVISION_LIBRARIES}" CACHE STRING "" FORCE)
mark_as_advanced(ALVISION_LIBRARIES)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ALVISION DEFAULT_MSG
  ALVISION_LIBRARIES
  ALVISION_INCLUDE_DIRS
)
# Right after find_package_handle_standard_args, _FOUND is
# set correctly.
# For instance, if foo/bar.h is not foud, FOO_FOUND is FALSE.
# But, right after this, since foo-config.cmake HAS been found, CMake
# re-set FOO_FOUND to TRUE.
# So we set _PACKAGE_FOUND in cache...
set(ALVISION_PACKAGE_FOUND ${ALVISION_FOUND} CACHE INTERNAL "" FORCE)
 