# CMakeList.txt : CMake project for HistogramEqualization, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project( HistogramEqualization )

# Add source to this project's executable.
add_executable (HistogramEqualization 
"HistogramEqualization.cpp" "HistogramEqualization.h"
)

# copy bin files and image files to build directory
add_custom_command(
	TARGET HistogramEqualization POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
		${OpenCV_BIN_DIR} 
		$<TARGET_FILE_DIR:HistogramEqualization>
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_CURRENT_SOURCE_DIR}/Image
		${CMAKE_CURRENT_BINARY_DIR}/Image
)

target_link_libraries( HistogramEqualization 
${OpenCV_LIBS}
HistogramLib
)