# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/scott/Documents/code/exercism/cpp/triangle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/scott/Documents/code/exercism/cpp/triangle

# Utility rule file for test_triangle.

# Include the progress variables for this target.
include CMakeFiles/test_triangle.dir/progress.make

CMakeFiles/test_triangle: triangle
	./triangle

test_triangle: CMakeFiles/test_triangle
test_triangle: CMakeFiles/test_triangle.dir/build.make

.PHONY : test_triangle

# Rule to build all files generated by this target.
CMakeFiles/test_triangle.dir/build: test_triangle

.PHONY : CMakeFiles/test_triangle.dir/build

CMakeFiles/test_triangle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_triangle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_triangle.dir/clean

CMakeFiles/test_triangle.dir/depend:
	cd /home/scott/Documents/code/exercism/cpp/triangle && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/scott/Documents/code/exercism/cpp/triangle /home/scott/Documents/code/exercism/cpp/triangle /home/scott/Documents/code/exercism/cpp/triangle /home/scott/Documents/code/exercism/cpp/triangle /home/scott/Documents/code/exercism/cpp/triangle/CMakeFiles/test_triangle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_triangle.dir/depend

