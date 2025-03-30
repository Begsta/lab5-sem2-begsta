cmake_minimum_required(VERSION 3.27.0)

set(project "structData")

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES structData.cpp)
set(${project}_HEADERSES structData.h)
set(${project}_SOURCE_LIST ${${project}_SOURCES} ${${project}_HEADERSES})

add_library(${project} STATIC ${${project}_SOURCE_LIST})