# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/fabio/clion-2017.3.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/fabio/clion-2017.3.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fabio/workspace/Hashcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fabio/workspace/Hashcode/build

# Include any dependencies generated for this target.
include CMakeFiles/serializer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/serializer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serializer.dir/flags.make

CMakeFiles/serializer.dir/src/serializer.cpp.o: CMakeFiles/serializer.dir/flags.make
CMakeFiles/serializer.dir/src/serializer.cpp.o: ../src/serializer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fabio/workspace/Hashcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/serializer.dir/src/serializer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serializer.dir/src/serializer.cpp.o -c /home/fabio/workspace/Hashcode/src/serializer.cpp

CMakeFiles/serializer.dir/src/serializer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serializer.dir/src/serializer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fabio/workspace/Hashcode/src/serializer.cpp > CMakeFiles/serializer.dir/src/serializer.cpp.i

CMakeFiles/serializer.dir/src/serializer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serializer.dir/src/serializer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fabio/workspace/Hashcode/src/serializer.cpp -o CMakeFiles/serializer.dir/src/serializer.cpp.s

CMakeFiles/serializer.dir/src/serializer.cpp.o.requires:

.PHONY : CMakeFiles/serializer.dir/src/serializer.cpp.o.requires

CMakeFiles/serializer.dir/src/serializer.cpp.o.provides: CMakeFiles/serializer.dir/src/serializer.cpp.o.requires
	$(MAKE) -f CMakeFiles/serializer.dir/build.make CMakeFiles/serializer.dir/src/serializer.cpp.o.provides.build
.PHONY : CMakeFiles/serializer.dir/src/serializer.cpp.o.provides

CMakeFiles/serializer.dir/src/serializer.cpp.o.provides.build: CMakeFiles/serializer.dir/src/serializer.cpp.o


# Object files for target serializer
serializer_OBJECTS = \
"CMakeFiles/serializer.dir/src/serializer.cpp.o"

# External object files for target serializer
serializer_EXTERNAL_OBJECTS =

libserializer.a: CMakeFiles/serializer.dir/src/serializer.cpp.o
libserializer.a: CMakeFiles/serializer.dir/build.make
libserializer.a: CMakeFiles/serializer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fabio/workspace/Hashcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libserializer.a"
	$(CMAKE_COMMAND) -P CMakeFiles/serializer.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serializer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serializer.dir/build: libserializer.a

.PHONY : CMakeFiles/serializer.dir/build

CMakeFiles/serializer.dir/requires: CMakeFiles/serializer.dir/src/serializer.cpp.o.requires

.PHONY : CMakeFiles/serializer.dir/requires

CMakeFiles/serializer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serializer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serializer.dir/clean

CMakeFiles/serializer.dir/depend:
	cd /home/fabio/workspace/Hashcode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fabio/workspace/Hashcode /home/fabio/workspace/Hashcode /home/fabio/workspace/Hashcode/build /home/fabio/workspace/Hashcode/build /home/fabio/workspace/Hashcode/build/CMakeFiles/serializer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/serializer.dir/depend

