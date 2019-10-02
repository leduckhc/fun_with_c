cmake_minimum_required(VERSION 3.1)
project(scratch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# libraries
set(LIBS ${OpenCV_LIBS})

# linking and compiling
add_executable(submatrix submatrix.cpp)
target_link_libraries(submatrix ${LIBS})

add_executable(submatrix2 submatrix2.cpp)
target_link_libraries(submatrix2 ${LIBS})

add_executable(opencv_ops opencv_ops.cpp)
target_link_libraries(opencv_ops ${LIBS})

add_executable(tuple tuple.cpp)
target_link_libraries(tuple ${LIBS})

add_executable(range range.cpp)
target_link_libraries(range ${LIBS})

