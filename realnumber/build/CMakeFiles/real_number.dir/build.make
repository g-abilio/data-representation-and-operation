# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gabilio/documents/Foundations/Data/realnumber

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gabilio/documents/Foundations/Data/realnumber/build

# Include any dependencies generated for this target.
include CMakeFiles/real_number.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/real_number.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/real_number.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/real_number.dir/flags.make

CMakeFiles/real_number.dir/realnumber.cpp.o: CMakeFiles/real_number.dir/flags.make
CMakeFiles/real_number.dir/realnumber.cpp.o: /Users/gabilio/documents/Foundations/Data/realnumber/realnumber.cpp
CMakeFiles/real_number.dir/realnumber.cpp.o: CMakeFiles/real_number.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/gabilio/documents/Foundations/Data/realnumber/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/real_number.dir/realnumber.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/real_number.dir/realnumber.cpp.o -MF CMakeFiles/real_number.dir/realnumber.cpp.o.d -o CMakeFiles/real_number.dir/realnumber.cpp.o -c /Users/gabilio/documents/Foundations/Data/realnumber/realnumber.cpp

CMakeFiles/real_number.dir/realnumber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/real_number.dir/realnumber.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gabilio/documents/Foundations/Data/realnumber/realnumber.cpp > CMakeFiles/real_number.dir/realnumber.cpp.i

CMakeFiles/real_number.dir/realnumber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/real_number.dir/realnumber.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gabilio/documents/Foundations/Data/realnumber/realnumber.cpp -o CMakeFiles/real_number.dir/realnumber.cpp.s

# Object files for target real_number
real_number_OBJECTS = \
"CMakeFiles/real_number.dir/realnumber.cpp.o"

# External object files for target real_number
real_number_EXTERNAL_OBJECTS =

real_number: CMakeFiles/real_number.dir/realnumber.cpp.o
real_number: CMakeFiles/real_number.dir/build.make
real_number: methods_/libmethods.a
real_number: CMakeFiles/real_number.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/gabilio/documents/Foundations/Data/realnumber/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable real_number"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/real_number.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/real_number.dir/build: real_number
.PHONY : CMakeFiles/real_number.dir/build

CMakeFiles/real_number.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/real_number.dir/cmake_clean.cmake
.PHONY : CMakeFiles/real_number.dir/clean

CMakeFiles/real_number.dir/depend:
	cd /Users/gabilio/documents/Foundations/Data/realnumber/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gabilio/documents/Foundations/Data/realnumber /Users/gabilio/documents/Foundations/Data/realnumber /Users/gabilio/documents/Foundations/Data/realnumber/build /Users/gabilio/documents/Foundations/Data/realnumber/build /Users/gabilio/documents/Foundations/Data/realnumber/build/CMakeFiles/real_number.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/real_number.dir/depend

