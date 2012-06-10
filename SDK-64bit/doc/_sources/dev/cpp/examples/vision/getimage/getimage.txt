.. _cpp-tutos-get-image:

Getting an image
================

:ref:`\<\< return to examples index <example-index>`

The aim of this example is to show how to retrieve images from NAO's cameras. The images will be displayed in a window, using OpenCV library. Press ESC to exit the application.

The whole example is available here: :download:`getimage.zip <../getimage.zip>`

Source file:
------------

:download:`getimages.cpp <getimages.cpp>`

.. literalinclude:: getimages.cpp
   :language: cpp

CMakeLists.txt:
---------------

The corresponding CMakeLists.txt file is the following:

:download:`CMakeLists.txt <CMakeLists.txt>`

.. literalinclude:: CMakeLists.txt
   :language: cmake

.. note::
   When running CMake, you might have to replace the default OpenCV libraries by the ones on
   your system. To do that, switch to *Advanced* view in Cmake-GUI and replace the arguments
   of OPENCV_INCLUDE_DIR and OPENCV_LIBRARIES with the OpenCV paths of your system.

