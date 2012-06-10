/**
* @author Aldebaran Robotics
* Copyright (c) Aldebaran Robotics 2007, 2011 All Rights Reserved
*/


// dcoz. 11/03/09. TODO: LOTS OF CLEANING:
//
// - Fix encoding format of the comments !
//
// - move functions to a proper namespace ! (eg ALTools:: )
//  (functions such as replace() are likely to create nasty conflicts)

#pragma once

#ifndef _LIB_ALTOOLS_ALTOOLS_TOOLS_H_
#define _LIB_ALTOOLS_ALTOOLS_TOOLS_H_

#include <qi/macro.hpp>

QI_DEPRECATED_HEADER("Use qi::os::spawn instead of LaunchShellCommand, use std::stringstream to format string")

#include <string>

std::string HexaToString(int pnValue);
std::string HexaToString(void* pnValue);
std::string DecToString(int pnValue);
std::string DoubleToString(double prValue);
std::string FloatToString(float prValue);
std::string BoolToString(bool pbValue);

// return a copy of strSrc with all strToFind replaced
std::string replace(const std::string& strSrc,
                    const std::string& strToFind,
                    const std::string& strToReplace,
                    bool bCaseSensitive = true);

const char* strstr_ignorecase(const char* szStringToBeSearched,
                              const char* szSubstringToSearchFor);

// Replace array zith AL::ALValue
std::string DocTypeString(const std::string& src);

// XML encode, leave br tags
std::string DocString(const std::string& src);

// Replace XML string with escape characters
std::string StringToXml(const std::string& strSrc, std::string& strDst, bool escapeSpaces = false);

// replace escape characters in html string
void XmlToString(const std::string& strSrc, std::string& strDst);


inline unsigned char klip(int val)
{
  if (val > 255)
  {
    return 255;
  }
  if (val < 0)
  {
    return 0;
  }
  return (unsigned char)val;
}

namespace ALTools
{
    bool isEmptyChar(const char ch);

    /**
    * convert string to lowercase
    */
    void convertToLowerCase(std::string& str);

  /**
   * Remove from a string all non alphabetic caracters : '/', '!', ',', ']'...
   * Leave numbers, alphabet, and also '_'.
   * Used by Choregraphe to handle box and I/O names.
   */
  std::string removeNonAlphabeticCaracters(const std::string pStr);

  // convert an hexa string to int.
  // 0xFF => 255 ...
  int hexaAsciiToInt(const char* str);

  //-----------------------------------------------------------------------------
  //  Name  :  firstNonEmptyChar
  /**
  * @param szInput a text to analyse, eg: " 1", "toto", or "  [36,3,"toto",3.5,[1,2,3]]"
  * @return the index [0..len-1] of the first interesting character (not ' ', nor '\t', ...)
  *
  * Object : Return the index of the first real char of a buffer
  *
  */
  // Created: Alma 09-02-02
  //-----------------------------------------------------------------------------
  int firstNonEmptyChar(const char* szInput);

  /**
  * isPrivateString
  * return true if string contain private string "ALFrameManager__"
  */
  bool isPrivateString(const std::string &pStr);

  std::string addXmlTag(const std::string& tag,
      const std::string& attr,
      const std::string& text);

  // return the timestamp of current time
  std::string TimeStamp(void);

  // TODO(dcoz): Rename this function. On linux, it doesn't need to use a shell.
  // will launch a shell command (on every platform)
  // return true when command succeed
  bool LaunchShellCommand(const char* pszCommandAndParameters[],
      bool bWaitUntilEndOfCommand = false);

  // return true si on est sur la geode, false sinon
  bool NaoCurrentExecutionIsOnGeode(void);
}
#endif  // _LIB_ALTOOLS_ALTOOLS_TOOLS_H_
