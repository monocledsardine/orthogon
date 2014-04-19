# Minimum required for SFML
cmake_minimum_required(VERSION 2.8)

project(Orthogon)

# Set the SFML_DIR cache variable
set(SFML_DIR "${PROJECT_BINARY_DIR}/SFML" CACHE FILEPATH "Root directory for SFML install")

# CMake needs these values to find SFML
set(CMAKE_MODULE_PATH "${SFML_DIR}/cmake/Modules")
set(CMAKE_PREFIX_PATH "${SFML_DIR}")

# Find SFML
find_package(SFML COMPONENTS system window graphics main)

# Handy error message for those unsavvy people
if (SFML_FOUND)
	message(STATUS "SFML Found!")
else(SFML_FOUND)
	set(SFML_LIBRARIES "")
	message(FATAL_ERROR "SFML was not found. Try setting SFML_DIR in the graphical interface.")
endif(SFML_FOUND)

# Include SFML header files
include_directories(${SFML_INCLUDE_DIR})

set(ORTHO_SRC
		Actor.cpp
		Actor.hpp
		Angle.cpp
		Angle.hpp
		Animation.cpp
		Animation.hpp
		DottedPath.cpp
		DottedPath.hpp
		ImageRef.hpp
		Path.cpp
		Path.hpp
		Player.cpp
		Player.hpp
		PlayerState.cpp
		PlayerState.hpp
		PlayerMotion.cpp
		PlayerMotion.hpp
		Room.hpp
		TiledImage.cpp
		TiledImage.hpp
		VectorHelper.hpp
)

add_library(ORTHO_LIB ${ORTHO_SRC})

add_executable(Orthogon Main.cpp)
add_executable(JumpTest JumpTest.cpp)

target_link_libraries(Orthogon ORTHO_LIB ${SFML_LIBRARIES})
target_link_libraries(JumpTest ORTHO_LIB ${SFML_LIBRARIES})

# Make sure the install prefix is in the graphical prompt
set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/../bin" CACHE FILEPATH "Install location of the project")

# To install the game, we need 1. The .exe, 2. SFML dlls, ...
install(TARGETS Orthogon DESTINATION .)
install(TARGETS JumpTest DESTINATION .)
install(FILES ${SFML_DIR}/bin/sfml-system-2.dll
			${SFML_DIR}/bin/sfml-window-2.dll
			${SFML_DIR}/bin/sfml-graphics-2.dll
			DESTINATION .)

# ...and 3. Images
install(DIRECTORY images DESTINATION .)

add_subdirectory(TestSuite)