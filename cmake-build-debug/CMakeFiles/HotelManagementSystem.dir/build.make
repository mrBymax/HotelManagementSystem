# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/federicobertossi/CLionProjects/HotelManagementSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/federicobertossi/CLionProjects/HotelManagementSystem/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HotelManagementSystem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HotelManagementSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HotelManagementSystem.dir/flags.make

CMakeFiles/HotelManagementSystem.dir/main.cpp.o: CMakeFiles/HotelManagementSystem.dir/flags.make
CMakeFiles/HotelManagementSystem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/federicobertossi/CLionProjects/HotelManagementSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HotelManagementSystem.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HotelManagementSystem.dir/main.cpp.o -c /Users/federicobertossi/CLionProjects/HotelManagementSystem/main.cpp

CMakeFiles/HotelManagementSystem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HotelManagementSystem.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/federicobertossi/CLionProjects/HotelManagementSystem/main.cpp > CMakeFiles/HotelManagementSystem.dir/main.cpp.i

CMakeFiles/HotelManagementSystem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HotelManagementSystem.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/federicobertossi/CLionProjects/HotelManagementSystem/main.cpp -o CMakeFiles/HotelManagementSystem.dir/main.cpp.s

# Object files for target HotelManagementSystem
HotelManagementSystem_OBJECTS = \
"CMakeFiles/HotelManagementSystem.dir/main.cpp.o"

# External object files for target HotelManagementSystem
HotelManagementSystem_EXTERNAL_OBJECTS =

HotelManagementSystem: CMakeFiles/HotelManagementSystem.dir/main.cpp.o
HotelManagementSystem: CMakeFiles/HotelManagementSystem.dir/build.make
HotelManagementSystem: CMakeFiles/HotelManagementSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/federicobertossi/CLionProjects/HotelManagementSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HotelManagementSystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HotelManagementSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HotelManagementSystem.dir/build: HotelManagementSystem

.PHONY : CMakeFiles/HotelManagementSystem.dir/build

CMakeFiles/HotelManagementSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HotelManagementSystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HotelManagementSystem.dir/clean

CMakeFiles/HotelManagementSystem.dir/depend:
	cd /Users/federicobertossi/CLionProjects/HotelManagementSystem/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/federicobertossi/CLionProjects/HotelManagementSystem /Users/federicobertossi/CLionProjects/HotelManagementSystem /Users/federicobertossi/CLionProjects/HotelManagementSystem/cmake-build-debug /Users/federicobertossi/CLionProjects/HotelManagementSystem/cmake-build-debug /Users/federicobertossi/CLionProjects/HotelManagementSystem/cmake-build-debug/CMakeFiles/HotelManagementSystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HotelManagementSystem.dir/depend
