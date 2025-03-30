# cmake_minimum_required(VERSION 3.27.0)
# set(project "lab5")

# project(${project})

# set(CMAKE_CXX_STANDARD 17)

# add_subdirectory(structData)

# find_program(CPPCHECK cppcheck)
# if(CPPCHECK)
#     set(CMAKE_CXX_CPPCHECK
#         ${CPPCHECK}
#         --suppress=missingInclude
#         --enable=all
#         --inconclusive
#         --std=c++17
#         --verbose
#         --xml
#         --xml-version=2)
# endif()

# message(STATUS "Project name: ${project}")
# message(STATUS "CXX_CPPCHECK: ${CMAKE_CXX_CPPCHECK}")

# if(CPPCHECK)
#     set_target_properties(${project} PROPERTIES
#                           CXX_CPPCHECK ${CMAKE_CXX_CPPCHECK})
# endif()

# add_executable(${project} main.cpp)
# target_link_libraries(${project} structData)

cmake_minimum_required(VERSION 3.27.0)
set(project "lab5")

project(${project})

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(structData)

find_program(CPPCHECK cppcheck)
if(CPPCHECK)
    set(CMAKE_CXX_CPPCHECK
        ${CPPCHECK}
        --suppress=missingInclude
        --enable=all
        --inconclusive
        --std=c++17
        --verbose
        --xml
        --xml-version=2)
endif()

message(STATUS "Project name: ${project}")
message(STATUS "CXX_CPPCHECK: ${CMAKE_CXX_CPPCHECK}")

add_executable(${project} main.cpp)
target_link_libraries(${project} structData)

# Optionally, you can add a custom command to run cppcheck
if(CPPCHECK)
    add_custom_target(run_cppcheck
        COMMAND ${CMAKE_CXX_CPPCHECK} ${CMAKE_SOURCE_DIR}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running cppcheck"
        VERBATIM)
endif()
