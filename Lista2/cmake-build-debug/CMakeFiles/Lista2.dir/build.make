# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/neo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4445.84/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/neo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4445.84/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/neo/Documents/Sezon_5/Modelowanie/modelowanie/Lista2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/neo/Documents/Sezon_5/Modelowanie/modelowanie/Lista2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lista2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lista2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lista2.dir/flags.make

CMakeFiles/Lista2.dir/main.cpp.o: CMakeFiles/Lista2.dir/flags.make
CMakeFiles/Lista2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neo/Documents/Sezon_5/Modelowanie/modelowanie/Lista2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lista2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lista2.dir/main.cpp.o -c /home/neo/Documents/Sezon_5/Modelowanie/modelowanie/Lista2/main.cpp

CMakeFiles/Lista2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lista2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neo/Documents/Sezon_5/Modelowanie/modelowanie/Lista2/main.cpp > CMakeFiles/Lista2.dir/main.cpp.i

CMakeFiles/Lista2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lista2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neo/Documents/Sezon_5/Modelowanie/modelowanie/Lista2/main.cpp -o CMakeFiles/Lista2.dir/main.cpp.s

CMakeFiles/Lista2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Lista2.dir/main.cpp.o.requires

CMakeFiles/Lista2.dir/main.cpp.o.provides: CMakeFiles/Lista2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lista2.dir/build.make CMakeFiles/Lista2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Lista2.dir/main.cpp.o.provides

CMakeFiles/Lista2.dir/main.cpp.o.provides.build: CMakeFiles/Lista2.dir/main.cpp.o


# Object files for target Lista2
Lista2_OBJECTS = \
"CMakeFiles/Lista2.dir/main.cpp.o"

# External object files for target Lista2
Lista2_EXTERNAL_OBJECTS =

Lista2: CMakeFiles/Lista2.dir/main.cpp.o
Lista2: CMakeFiles/Lista2.dir/build.make
Lista2: CMakeFiles/Lista2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/neo/Documents/Sezon_5/Modelowanie/modelowanie/Lista2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lista2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lista2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lista2.dir/build: Lista2

.PHONY : CMakeFiles/Lista2.dir/build

CMakeFiles/Lista2.dir/requires: CMakeFiles/Lista2.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Lista2.dir/requires

CMakeFiles/Lista2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lista2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lista2.dir/clean

CMakeFiles/Lista2.dir/depend:
	cd /home/neo/Documents/Sezon_5/Modelowanie/modelowanie/Lista2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/neo/Documents/Sezon_5/Modelowanie/modelowanie/Lista2 /home/neo/Documents/Sezon_5/Modelowanie/modelowanie/Lista2 /home/neo/Documents/Sezon_5/Modelowanie/modelowanie/Lista2/cmake-build-debug /home/neo/Documents/Sezon_5/Modelowanie/modelowanie/Lista2/cmake-build-debug /home/neo/Documents/Sezon_5/Modelowanie/modelowanie/Lista2/cmake-build-debug/CMakeFiles/Lista2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lista2.dir/depend

