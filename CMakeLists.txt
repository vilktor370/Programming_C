cmake_minimum_required(VERSION 3.0)
project(main)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Include OpenCV directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Add source files
add_executable(main Canny.cpp)

# Link OpenCV libraries
target_link_libraries(main ${OpenCV_LIBS})
