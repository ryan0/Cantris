cmake_minimum_required(VERSION 2.8.0)

set(CANTRIS_LIB_PATH "default-path" CACHE PATH "LOACTION of Dependancies")
if(CANTRIS_LIB_PATH STREQUAL "default-path")
	#default
else()
	set(CMAKE_PREFIX_PATH ${CANTRIS_LIB_PATH})
endif()

PROJECT(Rainsford)

# Rainsford version number
set(RAINSFORD_MAJOR 0)
set(RAINSFORD_MINOR 1)
set(RAINSFORD_PATCH 0)
set(RAINSFORD_VERSION ${RAINSFORD_MAJOR}.${RAINSFORD_MINOR}.${RAINSFORD_PATCH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_BUILD_TYPE Debug)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Location to look for modules
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

# Find the sfml2 headers and library
find_package(SFML 2 REQUIRED system window graphics audio)
include_directories(${SFML_INCLUDE_DIR})

# Find the lua headers and library
find_package(Lua REQUIRED)
include_directories(${LUA_INCLUDE_DIR})

# Find the Box2D headers and library
find_package(Box2D)
include_directories(${BOX2D_INCLUDE_DIR})


# include the 'include' directory
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)