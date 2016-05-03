
# Include sources from subdirectories
include(Components/CMakeLists.txt)
include(Core/CMakeLists.txt)
include(Engine/CMakeLists.txt)
include(GUI/CMakeLists.txt)
include(Messages/CMakeLists.txt)
include(Systems/CMakeLists.txt)


# Attach sources to the target
add_executable(
	Rainsford
		main.cpp
        ${RAINSFORD_COMPONENTS_SRC}
        ${RAINSFORD_CORE_SRC}
        ${RAINSFORD_ENGINE_SRC}
        ${RAINSFORD_GUI_SRC}
        ${RAINSFORD_MESSAGES_SRC}
        ${RAINSFORD_SYSTEMS_SRC}
)

# Attach dependancies to the executable
target_link_libraries(
	Rainsford
		${SFML_LIBRARIES}
		${LUA_LIBRARIES}
        ${BOX2D_LIBRARIES}
)