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
CMAKE_SOURCE_DIR = /home/scott/Documents/code/exercism/cpp/gigasecond

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/scott/Documents/code/exercism/cpp/gigasecond

# Utility rule file for test_gigasecond.

# Include the progress variables for this target.
include CMakeFiles/test_gigasecond.dir/progress.make

CMakeFiles/test_gigasecond: gigasecond
	./gigasecond

test_gigasecond: CMakeFiles/test_gigasecond
test_gigasecond: CMakeFiles/test_gigasecond.dir/build.make

.PHONY : test_gigasecond

# Rule to build all files generated by this target.
CMakeFiles/test_gigasecond.dir/build: test_gigasecond

.PHONY : CMakeFiles/test_gigasecond.dir/build

CMakeFiles/test_gigasecond.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_gigasecond.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_gigasecond.dir/clean

CMakeFiles/test_gigasecond.dir/depend:
	cd /home/scott/Documents/code/exercism/cpp/gigasecond && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/scott/Documents/code/exercism/cpp/gigasecond /home/scott/Documents/code/exercism/cpp/gigasecond /home/scott/Documents/code/exercism/cpp/gigasecond /home/scott/Documents/code/exercism/cpp/gigasecond /home/scott/Documents/code/exercism/cpp/gigasecond/CMakeFiles/test_gigasecond.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_gigasecond.dir/depend

