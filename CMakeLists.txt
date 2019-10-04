cmake_minimum_required(VERSION 3.1)
project(scratch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# boost
find_package(Boost 1.65 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# join all libraries
set(LIBS ${OpenCV_LIBS} ${Boost_LIBS})

# linking and compiling
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach(SRC ${SOURCES})
    # get filename without extension
    message("Compiling " ${SRC})
    get_filename_component(TRG ${SRC} NAME_WE)
    message("filename " ${TRG})
    add_executable(${TRG} ${SRC})
    target_link_libraries(${TRG} ${LIBS} dl)    
endforeach()


