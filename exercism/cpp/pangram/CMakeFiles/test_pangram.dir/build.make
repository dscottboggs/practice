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
CMAKE_SOURCE_DIR = /home/scott/Documents/code/exercism/cpp/pangram

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/scott/Documents/code/exercism/cpp/pangram

# Utility rule file for test_pangram.

# Include the progress variables for this target.
include CMakeFiles/test_pangram.dir/progress.make

CMakeFiles/test_pangram: pangram
	./pangram

test_pangram: CMakeFiles/test_pangram
test_pangram: CMakeFiles/test_pangram.dir/build.make

.PHONY : test_pangram

# Rule to build all files generated by this target.
CMakeFiles/test_pangram.dir/build: test_pangram

.PHONY : CMakeFiles/test_pangram.dir/build

CMakeFiles/test_pangram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_pangram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_pangram.dir/clean

CMakeFiles/test_pangram.dir/depend:
	cd /home/scott/Documents/code/exercism/cpp/pangram && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/scott/Documents/code/exercism/cpp/pangram /home/scott/Documents/code/exercism/cpp/pangram /home/scott/Documents/code/exercism/cpp/pangram /home/scott/Documents/code/exercism/cpp/pangram /home/scott/Documents/code/exercism/cpp/pangram/CMakeFiles/test_pangram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_pangram.dir/depend

