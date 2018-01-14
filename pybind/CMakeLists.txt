cmake_minimum_required(VERSION 2.6)
# Find Pangolin (https://github.com/stevenlovegrove/Pangolin)
find_package(Pangolin 0.4 REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
#execute_process(COMMAND python3 -m pybind11 --includes OUTPUT_VARIABLE Pybind11_INCLUDE_DIRS)
#MESSAGE( STATUS "CMAKE_BINARY_DIR:         " ${Pybind11_INCLUDE_DIRS} )
#include_directories(${Pybind11_INCLUDE_DIRS})

file(GLOB pypangolin_SRC
    "*.hpp"
    "*.cpp"
)

add_subdirectory(pybind11)
pybind11_add_module(pypangolin ${pypangolin_SRC})

#add_library(pypangolin SHARED ${pypangolin_SRC})
target_link_libraries(pypangolin ${Pangolin_LIBRARIES})
