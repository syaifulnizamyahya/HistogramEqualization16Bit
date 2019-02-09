# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ( HistogramEqulization16Bit )

# Make sure to configure this block
###############################################################################
set(OpenCV_DIR "D:/Project/DurrNDT/opencv")
# we want to copy OpenCV bin files to build dir
set(OpenCV_BIN_DIR "D:/Project/DurrNDT/opencv/x64/vc15/bin") 
###############################################################################

set(OpenCV_STATIC OFF) # If using OpenCV DLLs or dynamic libs
find_package(OpenCV 4.0.1 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Include sub-projects.
add_subdirectory ("HistogramEqualization")
add_library (HistogramLib Histogram/Histogram.cpp Histogram/Histogram.h)

enable_testing()
add_subdirectory("Histogram-Test")
add_test(Name HistogramTest Command Test)