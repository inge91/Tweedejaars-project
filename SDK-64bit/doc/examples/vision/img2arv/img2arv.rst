.. _cpp-examples-img2arv:

img2arv example
===============

:ref:`\<\< return to examples index <example-index>`

Overview
--------

Convert a serie of image to an arv video file.

Download
--------

The whole example is available here: :download:`img2arv.zip <../img2arv.zip>`

Source: img2arv.cpp
+++++++++++++++++++

Download :download:`img2arv.cpp <img2arv.cpp>`.

.. literalinclude:: img2arv.cpp
   :language: cpp

Source: CMakeLists.txt
++++++++++++++++++++++

Download :download:`CMakeLists.txt <CMakeLists.txt>`.

.. literalinclude:: CMakeLists.txt
   :language: cpp

.. note::
   When running CMake, you might have to replace the default OpenCV libraries by the ones on
   your system. To do that, switch to *Advanced* view in Cmake-GUI and replace the arguments
   of OPENCV_INCLUDE_DIR and OPENCV_LIBRARIES with the OpenCV paths of your system.

