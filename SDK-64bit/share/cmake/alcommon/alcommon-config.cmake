# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(ALCOMMON_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(ALCOMMON_INCLUDE_DIRS)
   
set(ALCOMMON_DEPENDS "QI;ALSOAP;RTTOOLS;ALTHREAD;BOOST_SIGNALS;BOOST_PROGRAM_OPTIONS;BOOST_FILESYSTEM;BOOST_THREAD;BOOST_DATE_TIME;PTHREAD;DL;ALVALUE;ALERROR;BOOST;TINYXML;RT;ALLOGREMOTE;QI;BOOST_FILESYSTEM;BOOST_THREAD;BOOST_DATE_TIME;PTHREAD;DL;ZEROMQ;UUID;DL;PYTHON;QI;ALSOAP;RTTOOLS;ALTHREAD;BOOST_SIGNALS;BOOST_PROGRAM_OPTIONS;BOOST_FILESYSTEM;BOOST_THREAD;BOOST_DATE_TIME;PTHREAD;DL;ALVALUE;ALERROR;BOOST;TINYXML;RT;ALLOGREMOTE;QI;BOOST_FILESYSTEM;BOOST_THREAD;BOOST_DATE_TIME;PTHREAD;DL;ZEROMQ;UUID;DL;PYTHON" CACHE STRING "" FORCE)
mark_as_advanced(ALCOMMON_DEPENDS)

set(ALCOMMON_DEFINITIONS "" CACHE STRING "" FORCE)
mark_as_advanced(ALCOMMON_DEFINITIONS)
 

find_library(ALCOMMON_DEBUG_LIBRARY alcommon_d)
find_library(ALCOMMON_LIBRARY       alcommon)


if (ALCOMMON_DEBUG_LIBRARY)
  set(ALCOMMON_LIBRARIES optimized;${ALCOMMON_LIBRARY};debug;${ALCOMMON_DEBUG_LIBRARY})
else()
  set(ALCOMMON_LIBRARIES ${ALCOMMON_LIBRARY})
endif()
set(ALCOMMON_LIBRARIES "${ALCOMMON_LIBRARIES}" CACHE STRING "" FORCE)
mark_as_advanced(ALCOMMON_LIBRARIES)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ALCOMMON DEFAULT_MSG
  ALCOMMON_LIBRARIES
  ALCOMMON_INCLUDE_DIRS
)
# Right after find_package_handle_standard_args, _FOUND is
# set correctly.
# For instance, if foo/bar.h is not foud, FOO_FOUND is FALSE.
# But, right after this, since foo-config.cmake HAS been found, CMake
# re-set FOO_FOUND to TRUE.
# So we set _PACKAGE_FOUND in cache...
set(ALCOMMON_PACKAGE_FOUND ${ALCOMMON_FOUND} CACHE INTERNAL "" FORCE)
 