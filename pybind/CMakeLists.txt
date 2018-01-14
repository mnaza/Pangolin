#
# Copyright (c) Andrey Mnatsakanov
#
cmake_minimum_required(VERSION 2.6)
# Find Pangolin (https://github.com/stevenlovegrove/Pangolin)
find_package(Pangolin 0.4 REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})

file(GLOB pypangolin_SRC
    "*.hpp"
    "*.cpp"
)

add_subdirectory(pybind11)
pybind11_add_module(pypangolin ${pypangolin_SRC})
target_link_libraries(pypangolin ${Pangolin_LIBRARIES})
