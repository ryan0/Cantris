cmake_minimum_required(VERSION 2.8.0)
PROJECT(Rainsford)

# Rainsford version number
set(RAINSFORD_MAJOR 0)
set(RAINSFORD_MINOR 1)
set(RAINSFORD_PATCH 0)
set(RAINSFORD_VERSION ${RAINSFORD_MAJOR}.${RAINSFORD_MINOR}.${RAINSFORD_PATCH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Location to look for modules
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

# Find the sfml2 headers and library
find_package(SFML 2 REQUIRED system window graphics audio)
include_directories(${SFML_INCLUDE_DIR})

# include the 'include' directory
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)