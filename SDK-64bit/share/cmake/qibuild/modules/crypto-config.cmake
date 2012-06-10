## Copyright (c) 2012 Aldebaran Robotics. All rights reserved.
## Use of this source code is governed by a BSD-style license that can be
## found in the COPYING file.

clean(CRYPTO)
fpath(CRYPTO ssl.h PATH_SUFFIXES openssl)
if(WIN32)
  flib(CRYPTO eay32)
  flib(CRYPTO ssleay32)
else()
  flib(CRYPTO ssl)
endif()
export_lib(CRYPTO)
