
# Find source and header files
file(GLOB_RECURSE RAINSFORD_SOURCES *.cpp)
file(GLOB_RECURSE RAINSFORD_HEADERS ${CMAKE_SOURCE_DIR}/include/*.hpp)

add_executable(
	Rainsford
		${RAINSFORD_SOURCES}
		${RAINSFORD_HEADERS}
)

target_link_libraries(
	Rainsford
		${SFML_LIBRARIES}
)