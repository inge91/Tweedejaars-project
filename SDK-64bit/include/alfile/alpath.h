/**
* @author Jerome Vuarand
* Copyright (c) Aldebaran Robotics 2010, 2011 All Rights Reserved
*/


#pragma once

#ifndef _LIB_ALFILE_ALFILE_ALPATH_H_
#define _LIB_ALFILE_ALFILE_ALPATH_H_

#include <qi/macro.hpp>

//QI_DEPRECATED_HEADER(Please use boost::filesystem instead)
#ifdef BOOST_FILESYSTEM_VERSION
#undef BOOST_FILESYSTEM_VERSION
#endif

#define BOOST_FILESYSTEM_VERSION 2
#include <boost/version.hpp>
#include <boost/filesystem.hpp>

namespace AL
{

  // these traits have utf-8 std::string on the program side, and on the external side:
  // - std::wstring on windows
  // - utf-8 std::string on other OSes
  // :TODO: use the real local 8-bit charset on the external side of other OSes
  struct ALPathTraits;

  typedef boost::filesystem2::basic_path<std::string, ALPathTraits> ALPath;
  typedef boost::filesystem2::basic_directory_iterator<ALPath> ALDirectoryIterator;
  typedef boost::filesystem2::basic_recursive_directory_iterator<ALPath> ALRecursiveDirectoryIterator;
  struct ALPathTraits
  {
#ifdef BOOST_WINDOWS_API
    typedef std::wstring external_string_type;
#else
    typedef std::string external_string_type;
#endif
    typedef std::string internal_string_type;
    static external_string_type to_external( const ALPath &, const internal_string_type & src );
    static internal_string_type to_internal( const external_string_type & src );
  };

} // namespace AL

namespace boost
{
  namespace filesystem2
  {

    template<> struct is_basic_path< ::AL::ALPath>
    { BOOST_STATIC_CONSTANT( bool, value = true ); };
  }

}

#endif  // _LIB_ALFILE_ALFILE_ALPATH_H_


