# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(ALTOOLS_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(ALTOOLS_INCLUDE_DIRS)
   
set(ALTOOLS_DEPENDS "QI;ALCORE;ALERROR;BOOST_FILESYSTEM;BOOST_THREAD;BOOST_DATE_TIME;PTHREAD;DL;QI;ALCORE;ALERROR;BOOST_FILESYSTEM;BOOST_THREAD;BOOST_DATE_TIME;PTHREAD;DL" CACHE STRING "" FORCE)
mark_as_advanced(ALTOOLS_DEPENDS)

set(ALTOOLS_DEFINITIONS "" CACHE STRING "" FORCE)
mark_as_advanced(ALTOOLS_DEFINITIONS)
 

find_library(ALTOOLS_DEBUG_LIBRARY altools_d)
find_library(ALTOOLS_LIBRARY       altools)


if (ALTOOLS_DEBUG_LIBRARY)
  set(ALTOOLS_LIBRARIES optimized;${ALTOOLS_LIBRARY};debug;${ALTOOLS_DEBUG_LIBRARY})
else()
  set(ALTOOLS_LIBRARIES ${ALTOOLS_LIBRARY})
endif()
set(ALTOOLS_LIBRARIES "${ALTOOLS_LIBRARIES}" CACHE STRING "" FORCE)
mark_as_advanced(ALTOOLS_LIBRARIES)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ALTOOLS DEFAULT_MSG
  ALTOOLS_LIBRARIES
  ALTOOLS_INCLUDE_DIRS
)
# Right after find_package_handle_standard_args, _FOUND is
# set correctly.
# For instance, if foo/bar.h is not foud, FOO_FOUND is FALSE.
# But, right after this, since foo-config.cmake HAS been found, CMake
# re-set FOO_FOUND to TRUE.
# So we set _PACKAGE_FOUND in cache...
set(ALTOOLS_PACKAGE_FOUND ${ALTOOLS_FOUND} CACHE INTERNAL "" FORCE)
 
if(NOT ALTOOLS_I_KNOW_IT_IS_DEPRECATED AND QI_WARN_DEPRECATED)
  message(STATUS "
    ${CMAKE_CURRENT_SOURCE_DIR}: altools is deprecated
    Please use qi::os, std::stringstream and boost::datetime instead.
  "
  )
  set(ALTOOLS_I_KNOW_IT_IS_DEPRECATED ON)
endif()
