# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eduardo/Downloads/ball-on-plate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eduardo/Downloads/ball-on-plate/build

# Include any dependencies generated for this target.
include serialComm/CMakeFiles/serialib.dir/depend.make

# Include the progress variables for this target.
include serialComm/CMakeFiles/serialib.dir/progress.make

# Include the compile flags for this target's objects.
include serialComm/CMakeFiles/serialib.dir/flags.make

serialComm/CMakeFiles/serialib.dir/serialib.cpp.o: serialComm/CMakeFiles/serialib.dir/flags.make
serialComm/CMakeFiles/serialib.dir/serialib.cpp.o: ../serialComm/serialib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eduardo/Downloads/ball-on-plate/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object serialComm/CMakeFiles/serialib.dir/serialib.cpp.o"
	cd /home/eduardo/Downloads/ball-on-plate/build/serialComm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serialib.dir/serialib.cpp.o -c /home/eduardo/Downloads/ball-on-plate/serialComm/serialib.cpp

serialComm/CMakeFiles/serialib.dir/serialib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serialib.dir/serialib.cpp.i"
	cd /home/eduardo/Downloads/ball-on-plate/build/serialComm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eduardo/Downloads/ball-on-plate/serialComm/serialib.cpp > CMakeFiles/serialib.dir/serialib.cpp.i

serialComm/CMakeFiles/serialib.dir/serialib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serialib.dir/serialib.cpp.s"
	cd /home/eduardo/Downloads/ball-on-plate/build/serialComm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eduardo/Downloads/ball-on-plate/serialComm/serialib.cpp -o CMakeFiles/serialib.dir/serialib.cpp.s

# Object files for target serialib
serialib_OBJECTS = \
"CMakeFiles/serialib.dir/serialib.cpp.o"

# External object files for target serialib
serialib_EXTERNAL_OBJECTS =

serialComm/libserialib.a: serialComm/CMakeFiles/serialib.dir/serialib.cpp.o
serialComm/libserialib.a: serialComm/CMakeFiles/serialib.dir/build.make
serialComm/libserialib.a: serialComm/CMakeFiles/serialib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eduardo/Downloads/ball-on-plate/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libserialib.a"
	cd /home/eduardo/Downloads/ball-on-plate/build/serialComm && $(CMAKE_COMMAND) -P CMakeFiles/serialib.dir/cmake_clean_target.cmake
	cd /home/eduardo/Downloads/ball-on-plate/build/serialComm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serialib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
serialComm/CMakeFiles/serialib.dir/build: serialComm/libserialib.a

.PHONY : serialComm/CMakeFiles/serialib.dir/build

serialComm/CMakeFiles/serialib.dir/clean:
	cd /home/eduardo/Downloads/ball-on-plate/build/serialComm && $(CMAKE_COMMAND) -P CMakeFiles/serialib.dir/cmake_clean.cmake
.PHONY : serialComm/CMakeFiles/serialib.dir/clean

serialComm/CMakeFiles/serialib.dir/depend:
	cd /home/eduardo/Downloads/ball-on-plate/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eduardo/Downloads/ball-on-plate /home/eduardo/Downloads/ball-on-plate/serialComm /home/eduardo/Downloads/ball-on-plate/build /home/eduardo/Downloads/ball-on-plate/build/serialComm /home/eduardo/Downloads/ball-on-plate/build/serialComm/CMakeFiles/serialib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : serialComm/CMakeFiles/serialib.dir/depend
