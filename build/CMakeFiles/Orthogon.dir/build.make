# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake 2.8\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake 2.8\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "C:\Program Files\CMake 2.8\bin\cmake-gui.exe"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Owner\Documents\GitHub\orthogon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Owner\Documents\GitHub\orthogon\build

# Include any dependencies generated for this target.
include CMakeFiles/Orthogon.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Orthogon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Orthogon.dir/flags.make

CMakeFiles/Orthogon.dir/Main.cpp.obj: CMakeFiles/Orthogon.dir/flags.make
CMakeFiles/Orthogon.dir/Main.cpp.obj: CMakeFiles/Orthogon.dir/includes_CXX.rsp
CMakeFiles/Orthogon.dir/Main.cpp.obj: ../Main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report C:\Users\Owner\Documents\GitHub\orthogon\build\CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Orthogon.dir/Main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\Orthogon.dir\Main.cpp.obj -c C:\Users\Owner\Documents\GitHub\orthogon\Main.cpp

CMakeFiles/Orthogon.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Orthogon.dir/Main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:\Users\Owner\Documents\GitHub\orthogon\Main.cpp > CMakeFiles\Orthogon.dir\Main.cpp.i

CMakeFiles/Orthogon.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Orthogon.dir/Main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:\Users\Owner\Documents\GitHub\orthogon\Main.cpp -o CMakeFiles\Orthogon.dir\Main.cpp.s

CMakeFiles/Orthogon.dir/Main.cpp.obj.requires:
.PHONY : CMakeFiles/Orthogon.dir/Main.cpp.obj.requires

CMakeFiles/Orthogon.dir/Main.cpp.obj.provides: CMakeFiles/Orthogon.dir/Main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Orthogon.dir\build.make CMakeFiles/Orthogon.dir/Main.cpp.obj.provides.build
.PHONY : CMakeFiles/Orthogon.dir/Main.cpp.obj.provides

CMakeFiles/Orthogon.dir/Main.cpp.obj.provides.build: CMakeFiles/Orthogon.dir/Main.cpp.obj

# Object files for target Orthogon
Orthogon_OBJECTS = \
"CMakeFiles/Orthogon.dir/Main.cpp.obj"

# External object files for target Orthogon
Orthogon_EXTERNAL_OBJECTS =

Orthogon.exe: CMakeFiles/Orthogon.dir/Main.cpp.obj
Orthogon.exe: CMakeFiles/Orthogon.dir/build.make
Orthogon.exe: libORTHO_LIB.a
Orthogon.exe: C:/Users/Owner/Documents/GitHub/crossing-over/build/SFML/lib/libsfml-system.a
Orthogon.exe: C:/Users/Owner/Documents/GitHub/crossing-over/build/SFML/lib/libsfml-window.a
Orthogon.exe: C:/Users/Owner/Documents/GitHub/crossing-over/build/SFML/lib/libsfml-graphics.a
Orthogon.exe: C:/Users/Owner/Documents/GitHub/crossing-over/build/SFML/lib/libsfml-main.a
Orthogon.exe: CMakeFiles/Orthogon.dir/objects1.rsp
Orthogon.exe: CMakeFiles/Orthogon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Orthogon.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Orthogon.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Orthogon.dir/build: Orthogon.exe
.PHONY : CMakeFiles/Orthogon.dir/build

CMakeFiles/Orthogon.dir/requires: CMakeFiles/Orthogon.dir/Main.cpp.obj.requires
.PHONY : CMakeFiles/Orthogon.dir/requires

CMakeFiles/Orthogon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Orthogon.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Orthogon.dir/clean

CMakeFiles/Orthogon.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Owner\Documents\GitHub\orthogon C:\Users\Owner\Documents\GitHub\orthogon C:\Users\Owner\Documents\GitHub\orthogon\build C:\Users\Owner\Documents\GitHub\orthogon\build C:\Users\Owner\Documents\GitHub\orthogon\build\CMakeFiles\Orthogon.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Orthogon.dir/depend

